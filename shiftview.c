/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */
#define TAGS_LEN 5

void
shiftview(const Arg *arg) {
	Arg shifted;

	if(arg->i > 0) // left circular shift
		shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)
		   | (selmon->tagset[selmon->seltags] >> (TAGS_LEN - arg->i));

	else // right circular shift
		shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)
		   | selmon->tagset[selmon->seltags] << (TAGS_LEN + arg->i);

	view(&shifted);
}

/*
 *   6 void                                                                                                                                                                                     
  5 shiftview(const Arg *arg) {                                                                                                                                                              
  4         Arg shifted;                                                                                                                                                                     
  3                                                                                                                                                                                          
  2         if(arg->i > 0) // left circular shift                                                                                                                                            
  1                 shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)                                                                                                                 
12                     | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));                                                                                                       
  1                                                                                                                                                                                          
  2         else // right circular shift                                                                                                                                                     
  3                 shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)                                                                                                               
  4                    | selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);                                                                                                         
  5                                                                                                                                                                                          
  6         view(&shifted);                                                                                                                                                                  
  7 } 
  */

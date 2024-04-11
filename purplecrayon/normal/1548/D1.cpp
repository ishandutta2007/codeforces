#include <iostream>
int64_t i=4,j,n,m,r,s[6],k;main(){std::cin>>n;m=n;while(n--){std::cin>>k>>j;s[(k&2)+(j&2)/2]++;}while(i--){k=s[i];r+=k*(k-1)*(k-2)/6+k*(k-1)*(m-k)/2;}std::cout<<r;}
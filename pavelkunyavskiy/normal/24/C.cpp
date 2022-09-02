#include <iostream>
__int64 n,k,x,y,a['   '],b['   '],d,i;
int main()
{
std::cin>>n>>k>>x>>y;
for(k%=2*n;std::cin>>a[d]>>b[d] && d<k;) x=2*a[d]-x,y=2*b[d++]-y;
for (k-=n;k>0;--k) x=2*a[i]-x,y=2*b[i++]-y;
std::cout<<x<<" "<<y;
}
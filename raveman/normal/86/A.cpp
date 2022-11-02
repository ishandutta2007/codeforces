#include <iostream>
main() {
__int64 l,r,a=1,p;
std::cin>>l>>r;
while(a<=r)a*=10;
p=std::min(std::max(a/2,l),r);
std::cout<<p*(a-1-p);
}
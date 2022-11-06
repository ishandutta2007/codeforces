#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

int main()
{
    int s=0;
    for(int x,i=0; i<5; ++i) read(x), s+=x;
    if(s%5 || s/5==0) puts("-1");
    else printf("%d\n", s/5);
    return 0;
}
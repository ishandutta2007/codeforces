#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

int main()
{
    int n, k;
    read(n, k);
    k = 240-k;
    int cnt = 0;
    for(; cnt<n; ){
        if(k < 5*(cnt+1)) break;
        k -= 5*(cnt+1);
        ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}
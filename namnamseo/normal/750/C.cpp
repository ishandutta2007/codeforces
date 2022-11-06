#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

typedef long long ll;

const ll inf = (1LL<<58);

int n;

int main()
{
    read(n);
    ll rL = -inf, rR = inf;
    for(;n--;){
        int c, d;
        read(c, d);
        if(d==1){
            rL = max(rL, 1900ll);
            if(rL > rR){
                puts("Impossible");
                return 0;
            }
        } else if(d==2){
            rR = min(rR, 1899ll);
            if(rL > rR){
                puts("Impossible");
                return 0;
            }
        }
        if(rL != -inf) rL += c;
        if(rR !=  inf) rR += c;
    }
    if(rR == inf) puts("Infinity");
    else printf("%I64d\n", rR);
    return 0;
}
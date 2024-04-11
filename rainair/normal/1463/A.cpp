#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        LL sm = a+b+c;
        if(sm%9){
            puts("NO");
            continue;
        }
        if((sm/9) <= std::min({a,b,c})){
            puts("YES");
        }
        else puts("NO");
    }
    return 0;
}
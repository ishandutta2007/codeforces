#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
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
        int a,b;scanf("%d%d",&a,&b);
        int ans = 0;
        if(b == 1) ++b,++ans;
        int mx = 0,t = a;
        while(t) t /= b,++mx;
        int res = ans+mx;
        FOR(i,1,mx){
            int t = a,c = i;
            while(t) ++c,t /= (i+b);
            res = std::min(res,c+ans);
        }
        printf("%d\n",res);
    }
    return 0;
}
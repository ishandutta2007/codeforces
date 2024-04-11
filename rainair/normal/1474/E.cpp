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
#define DEBUG(x) std::cerr <<#x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int p[MAXN],n;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        int las = 1;
        LL ans = 1ll*(n-1)*(n-1);
        // (n-2)/2
        FOR(i,n-(n-2)/2,n-1){
            p[las] = i;
            las = i;
            ans += 1ll*(i-1)*(i-1);
        }
        p[las] = n;las = n;
        FOR(i,2,n-(n-2)/2-1){
            p[las] = i;
            las = i;
            ans += 1ll*(n-i)*(n-i);
        }
        p[las] = 1;
        printf("%lld\n",ans);
        FOR(i,1,n) printf("%d%c",p[i]," \n"[i==n]);
        printf("%d\n",n-1);
        FOR(i,n-(n-2)/2,n-1) printf("%d %d\n",i,1);
        FOR(i,2,n-(n-2)/2-1) printf("%d %d\n",i,n);
        printf("%d %d\n",1,n);
    }
    return 0;
}
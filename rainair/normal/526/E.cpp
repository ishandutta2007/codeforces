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

const int MAXN = 1e6 + 5;
int n,q,a[MAXN];
int f[MAXN];

int main(){
    scanf("%d%d",&n,&q);
    LL s = 0;
    FOR(i,0,n-1) scanf("%d",a+i),s += a[i];
    while(q--){
        LL b;scanf("%lld",&b);
        if(s <= b){
            puts("1");
            continue;
        }
        LL sm = 0,t = 0;
        FOR(i,0,n-1){
            while(sm+a[(i+t)%n] <= b) sm += a[(i+t)%n],++t;
            f[i] = t;
            sm -= a[i];t--;
        }
        sm = 0;int now = 0;
        int mn = 1e9,ps = -1;
        while(sm < n){
            if(mn > f[now]){
                mn = f[now];
                ps = now;
            }
            sm += f[now];
            (now += f[now]) %= n;
        }
        int ans = 1e9;
        FOR(i,0,f[ps]){
            int t = (ps+i)%n;
            auto work = [&](int x){
                int ans = 0,sm = 0;
                while(sm < n){
                    ans++;sm += f[x];
                    (x += f[x]) %= n;
                }
                return ans;
            };
            ans = std::min(ans,work(t));
        }
        printf("%d\n",ans);
    }
    return 0;
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(LL i = a;i <= b;++i)
#define ROF(i,a,b) for(LL i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL

inline int get(int x){
    int res = 0;
    while(x) res += x%10,x /= 10;
    return res;
}

inline void Solve(){
    int n,k;scanf("%lld%lld",&n,&k);
    LL ans = 1e18;
    FOR(num0,0,9){
        FOR(j,0,17){
            if(num0+k <= 9){
                int sm = 9*j*(k+1);
                FOR(x,num0,num0+k) sm += x;
                sm = n-sm;
                if(sm < 0) continue;
                int now = 0;
                if(sm == 0){
                    FOR(i,1,j) now = now*10+9;
                    now = now*10+num0;
                    ans = std::min(ans,now);
                    continue;
                }
                if(sm%(k+1)) continue;
                sm /= (k+1);
                int d = sm/9,r = sm%9;
                now = r;
                if(d+j+1 > 17) continue;
                FOR(i,1,d+j) now = now*10+9;
                now = now*10+num0;
                ans = std::min(ans,now);
            }
            else{
                int sm = 9ll*j*(9-num0+1);
                FOR(x,num0,num0+k) sm += (x%10);
                sm += (num0+k-9);
                sm = n-sm;
                if(sm < 0) continue;
                int now = 0;
                if(sm == 0){
                    FOR(i,1,j) now = now*10+9;
                    now = now*10+num0;
                    ans = std::min(ans,now);
                    continue;
                }
                if(sm%(k+1)) continue;
                sm /= (k+1);
                int d = sm/9;
                if(d+j+1 > 17) continue;
                if(sm < 9){
                    now = sm;
                    FOR(i,1,j) now = now*10+9;
                    now = now*10+num0;
                }
                else{
                    sm -= 8;
                    int d = sm/9,r = sm%9;
                    now = r;
                    FOR(i,1,d) now = now*10+9;
                    now = now*10+8;
                    FOR(i,1,j) now = now*10+9;
                    now = now*10+num0;
                }
                ans = std::min(ans,now);
            }
        }
    }
//    DEBUG(ans);
    if(ans != 1e18){
    int tt = 0;
    FOR(x,ans,ans+k){
        tt += get(x);
    }
//    DEBUG(tt);
    assert(tt==n);
    }
    printf("%lld\n",ans==1e18?-1:ans);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}
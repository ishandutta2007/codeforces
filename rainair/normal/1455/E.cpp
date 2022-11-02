#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,LL>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

LL xx[5],yy[5],x[5],y[5];
int p[5];

inline LL mabs(LL x){
    return x < 0 ? -x : x;
}

std::vector<LL> S;

inline LL gao(){
    std::sort(all(S));
    int t = S.size()>>1;
    LL p = -S[t-1],res = 0;
    for(auto x:S) res += abs(x+p);
    return res;
}

inline void Solve(){
    FOR(i,1,4) scanf("%lld%lld",xx+i,yy+i),p[i] = i;
    LL ans = 1e18;
    do{
        FOR(i,1,4) x[p[i]] = xx[i],y[p[i]] = yy[i];
        for(auto i:{1,3}){
            for(auto j:{1,2}){
                S.clear();
                LL c = abs(x[1]-x[i])+abs(x[3]-x[i])+abs(y[1]-y[j])+abs(y[2]-y[j]);
                for(auto k:{2,4}) S.pb(x[i]-x[k]);
                for(auto k:{3,4}) S.pb(y[j]-y[k]);
                std::vector<LL> T = S;
                LL mn = 1e18;
                mn = std::min(mn,gao());
                S=T;FOR(k,0,1) S[k] = -S[k];
                mn = std::min(mn,gao());
                S=T;FOR(k,2,3) S[k] = -S[k];
                mn = std::min(mn,gao());
                S=T;FOR(k,0,1) S[k] = -S[k];
                mn = std::min(mn,gao());
                c += mn;
                ans = std::min(ans,c);
            }
        }
    }while(std::next_permutation(p+1,p+4+1));
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
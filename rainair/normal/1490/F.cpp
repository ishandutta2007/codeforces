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

const int MAXN = 2e5 + 5;
int n,a[MAXN],cnt[MAXN];

inline void Solve(){
    scanf("%d",&n);
    std::vector<int> S;
    FOR(i,1,n) scanf("%d",a+i),S.pb(a[i]);
    std::sort(all(S));S.erase(std::unique(all(S)),S.end());
    FOR(i,1,n) a[i] =std::lower_bound(all(S),a[i])-S.begin()+1;
    int m = SZ(S);
    FOR(i,1,m) cnt[i] = 0;
    FOR(i,1,n) ++cnt[a[i]];
    S.clear();FOR(i,1,m) if(cnt[i]) S.pb(cnt[i]);
    std::sort(all(S));
    int ans = 0;
    ROF(i,SZ(S)-1,0) ans = std::max(ans,S[i]*(SZ(S)-i));
    printf("%d\n",n-ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
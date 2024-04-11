#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
const int MAXN = 5e5 + 5;
int n,l[MAXN],r[MAXN],sm1[MAXN],sm2[MAXN];
std::vector<int> S;

inline void Solve(){
    S.clear();
    scanf("%d",&n);FOR(i,1,n) scanf("%d%d",l+i,r+i),S.pb(l[i]),S.pb(r[i]);
    std::sort(all(S));S.erase(std::unique(all(S)),S.end());
    FOR(i,1,n) l[i] = std::lower_bound(all(S),l[i])-S.begin()+1,r[i] = std::lower_bound(all(S),r[i])-S.begin()+1;
    int m = S.size();
    FOR(i,1,n) sm1[r[i]]++,sm2[l[i]]++;
    FOR(i,1,m) sm1[i] += sm1[i-1];ROF(i,m,1) sm2[i] += sm2[i+1];
    int ans = 0;FOR(i,1,n) ans = std::max(ans,n-sm1[l[i]-1]-sm2[r[i]+1]);
    printf("%d\n",n-ans);
    FOR(i,0,m) sm1[i] = sm2[i] = 0;
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
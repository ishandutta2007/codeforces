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

const int MAXN = 5e5 + 5;
int n,a[MAXN];
int ls[MAXN],rs[MAXN],sz[MAXN];
std::vector<int> G[MAXN];
int f[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),rs[a[i]] = i,++sz[a[i]];
//    FOR(i,1,n) assert(a[i] <= n);
    ROF(i,n,1) ls[a[i]] = i;
    FOR(i,1,n) if(ls[i]) G[rs[i]].pb(i);
    int len = 1;while(len < n && a[n-len] == a[n]) ++len;
    FOR(i,1,n){
        f[i] = f[i-1];
        for(auto x:G[i]){
            int c = f[ls[x]-1]+sz[x];
            if(i == n && x != a[n]) c += len;
            f[i] = std::max(f[i],c);
        }
    }
    int ans = 0,mx = 0;
    CLR(sz,0);
    ROF(i,n,1){
        ans = std::max(ans,mx+f[i]);
        ++sz[a[i]];mx = std::max(mx,sz[a[i]]);
    }
    printf("%d\n",n-ans);
    return 0;
}
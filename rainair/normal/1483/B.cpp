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

const int MAXN = 1e5 + 5;
int a[MAXN],n,nxt[MAXN],pre[MAXN];
bool del[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),del[i] = 0;
    FOR(i,1,n) nxt[i] = i%n+1,pre[nxt[i]] = i;
    std::queue<P<int,int> > q;
    FOR(i,1,n) if(std::__gcd(a[i],a[nxt[i]]) == 1) q.push(MP(i,nxt[i]));
    std::vector<int> ans;
    while(!q.empty()){
        int u,v;std::tie(v,u) = q.front();q.pop();
        if(del[u] || del[v]) continue;del[u] = 1;
        ans.pb(u);
        pre[nxt[nxt[v]]] = v;
        nxt[v] = nxt[nxt[v]];
        if(std::__gcd(a[v],a[nxt[v]]) == 1) q.push(MP(v,nxt[v]));
    }
    printf("%d ",SZ(ans));
    for(auto x:ans) printf("%d ",x);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
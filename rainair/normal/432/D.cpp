#include<bits/stdc++.h>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
char str[MAXN];
int nxt[MAXN];
int n;
std::vector<int> G[MAXN];
int sz[MAXN];

inline void dfs(int v){
    sz[v] = 1;
    for(auto x:G[v]){
        dfs(x);sz[v] += sz[x];
    }
}
std::vector<P> ans;
int main(){
    scanf("%s",str+1);n = strlen(str+1);
    nxt[1] = 0;
    FOR(i,2,n){
        int j = nxt[i-1];
        while(j && str[j+1] != str[i]) j = nxt[j];
        if(str[j+1] == str[i]) nxt[i] = j+1;
        else nxt[i] = 0;
    }
    FOR(i,1,n) DEBUG(nxt[i]);
    FOR(i,1,n) G[nxt[i]].pb(i);
    dfs(0);
    int now = n;
    while(now) ans.pb(MP(now,sz[now])),now = nxt[now];
    printf("%lu\n",ans.size());
    std::reverse(all(ans));
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
    return 0;
}
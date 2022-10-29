// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
   
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef unsigned long long ull;
// head

const int N=1e6+5;
int n,k;
vi e[N],ed[N];
int fa[N],d[N],sz[N];

int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void unite(int x,int y) {
    int fx=find(x),fy=find(y);
    if (fx==fy) return;
    if (fy>fx) swap(fx,fy);
    d[fy]=min(d[fy],d[fx]);
    sz[fy]+=sz[fx];
    fa[fx]=fy;
}

int dep[N];
void dfs(int u) {
    if (!SZ(e[u])) d[u]=dep[u],sz[u]=1;
    rep(i,0,SZ(e[u])) {
        int v=e[u][i];
        dep[v]=dep[u]+1;
        dfs(v);
        // bug(u),bug(v),bug(dep[u]);
        // printf(" %d\n",d[find(v)]);
        if (d[find(v)]-dep[u]<=k) {
            unite(u,v);
        }
    }
}  
int dp[N],mark[N];
void gao(int u,int f) {
    if (mark[u]) return;
    // bug(u),bug(sz[u]),debug(f);
    rep(i,0,SZ(ed[u])) {
        int v=ed[u][i];
        if (v==f) continue;
        gao(v,u);
        dp[u]=max(dp[u],dp[v]);
    }
    dp[u]+=sz[u];
    mark[u]=1;
}

int main() {
    // freopen("data","r",stdin);
    // freopen("1.out","w",stdout);
    scanf("%d%d",&n,&k);
    rep(i,1,n+1) fa[i]=i,d[i]=inf;
    rep(i,2,n+1) {
        int p;
        scanf("%d",&p);
        e[p].pb(i);
    }
    dfs(1);
    // rep(i,1,n+1) printf("fa[%d]=%d sz=%d\n",i,find(i),sz[find(i)]);
    rep(u,1,n+1) {
        rep(i,0,SZ(e[u])) {
            int v=e[u][i];
            if (find(u)!=find(v)) ed[find(u)].pb(find(v));
        }
    }
    gao(1,0);
    printf("%d\n",dp[1]);
    // debug(dp[1]);
    return 0;   
}
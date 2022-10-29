#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef unsigned long long ull;
const int inf=1<<30;
const int mod=998244353;
int rnd(int x) {return mrand()%x;}
// head
const int N=2e5+5;
int n,m;
VI e[N];

namespace TreeChain {// LCA
    int clk,sz[N],fa[N],dep[N],son[N];
    int lt[N],rt[N],top[N];
    void dfs1(int u,int f) {
        sz[u]=1,dep[u]=dep[f]+1;
        fa[u]=f; son[u]=0;
        for (auto v:e[u]) {
            if (v==f) continue;
            dfs1(v,u);
            sz[u]+=sz[v];
            if (sz[v]>sz[son[u]]) son[u]=v;
        }

    }
    void dfs2(int u,int tp) {
        lt[u]=++clk;
        top[u]=tp;
        // bug(u),bug(son[u]),debug(tp);
        if (son[u]) dfs2(son[u],tp);
        for (auto v:e[u]) {
            if (v==fa[u]||v==son[u]) continue;
            dfs2(v,v);
        }
        rt[u]=clk;
    }
    int LCA(int u,int v) {
        while (top[u]!=top[v]) {
            if (dep[top[u]]>dep[top[v]]) u=fa[top[u]];
            else v=fa[top[v]];  
        }
        return dep[u]>dep[v]?v:u;
    }
}
using namespace TreeChain;
template <typename T>
struct Fenwick {
    int n;
    vector<T> sum;
    Fenwick(int n):n(n),sum(n+1) {}
    int lowbit(int x) {return x&(-x);}
    void add(int x, T v) {
        if (x<=0) return;

        for (int i=x;i<=n;i+=lowbit(i)) {
            sum[i]+=v;
        }
    }
    T query(int x) {
        if (x<0) return 0;
        if (x>n) x=n;

        T res=0;
        for (int i=x;i>0;i-=lowbit(i)) {
            res+=sum[i];
        }
        return res;
    }
    T range(int l, int r) {
        return query(r)-query(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    cout << fixed << setprecision(6);

    cin >> n;
    rep(i,1,n) {
        int u,v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs1(1,0);
    dfs2(1,1);

    vector fen(21,Fenwick<int>(n));
    vector w(n+1,vector<int>(21));
    
    cin >> m;
    while (m--) {
        int op;
        cin >> op;

        if (op==1) {// query
            int x;
            int ans=0;
            cin >> x;
            for (int d=0,u=x;d<21 && u;d++,u=fa[u]) {
                ans+=fen[d].query(lt[u]);
                ans+=accumulate(w[u].begin()+d,w[u].end(),0);
            }
            cout << ans << endl;
        } else {// update
            int u,v,k,d;
            cin >> u >> v >> k >> d;
            while (top[u]!=top[v]) {
                if (dep[top[u]]<dep[top[v]]) swap(u,v);
                fen[d].add(lt[top[u]],+k);
                fen[d].add(lt[u]+1,-k);
                u=fa[top[u]];
            }
            if (dep[u]>dep[v]) swap(u,v);// u is LCA
            if (u!=v) fen[d].add(lt[u]+1,+k),fen[d].add(lt[v]+1,-k);

            for (int cur=u,j=d,son=-1;~j && cur;son=cur,j--,cur=fa[cur]) {
                w[cur][j]+=k;
                if (~son&&j) w[son][j-1]-=k;
            }
        }

    }
    return 0;
}
/*
test1
6
1 2
1 3
4 2
5 2
3 6
2
2 3 2 10 0
1 1

2 5 2 10 1
2 4 5 10 2
2 1 1 10 20
2 6 6 10 20


*/
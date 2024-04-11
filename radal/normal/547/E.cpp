#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 2e5+10,mod = 1e9+7,inf = 1e9,sq = 700,sig = 26;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int nxt[N][sig],sz,f[N],ind[N],T,tin[N],tout[N];
ll fen[2*N];
vector<int> adj[N];
pair<pll,int> Q[N*3];
ll ans[N*3];
bool vis[N*3];
string S[N];
vector<int> a[N]; 
inline int add_trie(string s){
    int cur = 0;
    int n = s.size();
    rep(i,0,n){
        int c = s[i]-'a';
        if (nxt[cur][c]) cur = nxt[cur][c];
        else{
            sz++;
            nxt[cur][c] = sz;
            cur = sz;
        }
    }
    return cur;
}
inline void buildaho(){
    queue<int> q;
    rep(i,0,26)
        if (nxt[0][i])
            q.push(nxt[0][i]);
    while (!q.empty()){
        int v = q.front();
        adj[f[v]].pb(v);
        q.pop();
        rep(i,0,26){
            if (nxt[v][i]){
                f[nxt[v][i]] = nxt[f[v]][i];
                q.push(nxt[v][i]);
            }
            else nxt[v][i] = nxt[f[v]][i];
        }
    }
}
void dfs(int v){
    tin[v] = T;
    T++;
    for (int u : adj[v])
        dfs(u);
    tout[v] = T;
    T++;
}
inline void upd(int l,int x){
    for (; l < 2*N; l |= (l+1))
        fen[l] += x;
}
inline ll que(int l,int r){
    ll res = 0;
    l--;
    r--;
    for (; l >= 0; l = (l&(l+1))-1) res -= fen[l];
    for (; r >= 0; r = (r&(r+1))-1) res += fen[r];
    return res;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,1,n+1){
        cin >> S[i];
        ind[i] = add_trie(S[i]);
    }
    buildaho();
    dfs(0);
    rep(i,0,q){
        cin >> Q[i].X.X >> Q[i].X.Y >> Q[i].Y;
        a[Q[i].X.X-1].pb(i);
        a[Q[i].X.Y].pb(i);
    }
    for (int u : a[0]) vis[u] = 1;
    rep(i,1,n+1){
        int v = 0;
        for (int c : S[i]){
            v = nxt[v][c-'a'];
            upd(tin[v],1);
        }
        for (int j : a[i]){
            int k = Q[j].Y;
            if (vis[j]){
                ans[j] += que(tin[ind[k]],tout[ind[k]]+1);
            }
            else{
                vis[j] = 1;
                ans[j] -= que(tin[ind[k]],tout[ind[k]]+1);
            }
        }
    }
    rep (i,0,q) cout << ans[i] << endl;
    return 0;
}
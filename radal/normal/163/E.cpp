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
const long long int N = 1e6+10,mod = 1e9+7,inf = 1e9,sq = 700,sig = 26;
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
bool o[N];
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
inline void upd(int l,int r,int x){
    upd(r,-x);
    upd(l,x);
}
inline ll que(int v){
    ll res = 0;
    for(; v >= 0; v = (v&(v+1))-1) res += fen[v];
    return res;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,q;
    cin >> q >> n;
    rep(i,0,n){
        string s;
        cin >> s;
        ind[i] = add_trie(s);
    }
    buildaho();
    dfs(0);
    rep(i,0,n){
        upd(tin[ind[i]],tout[ind[i]]+1,1);
        o[i] = 1;
    }
    while (q--){
        char c;
        cin >> c;
        if (c == '+'){
            int i;
            cin >> i;
            i--;
            if (o[i]) continue;
            upd(tin[ind[i]],tout[ind[i]]+1,1);
            o[i] = 1;
            continue;
        }
        if (c == '-'){
            int i;
            cin >> i;
            i--;
            if (!o[i]) continue;
            upd(tin[ind[i]],tout[ind[i]]+1,-1);
            o[i] = 0;
            continue;
        }
        string s;
        cin >> s;
        int m = s.size(),cur = 0;
        ll ans = 0;
        rep(i,0,m){
            cur = nxt[cur][s[i]-'a'];
            ans += que(tin[cur]);
        }
        cout << ans << endl;
    }
    return 0;
}
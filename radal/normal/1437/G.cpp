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
int nxt[N][sig],sz,ind[N],f[N];
vector<int> adj[N];
int val[N],par[N],a[N];
multiset<int> st[N];
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
    for (int u : adj[v]){
        if (val[v] >= 0) par[u] = v;
        else par[u] = par[v];
        dfs(u);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    memset(val,-1,sizeof val);
    memset(par,-1,sizeof par);
    int n,q;
    cin >> n >> q;
    rep(i,1,n+1){
        string s;
        cin >> s;
        ind[i] = add_trie(s);
        a[ind[i]] = 0;
        val[ind[i]] = 0;
        st[ind[i]].insert(0);
    }
    buildaho();
    dfs(0);
    while (q--){
        int t;
        cin >> t;
        if (t == 2){
            string q;
            cin >> q;
            int v = 0;
            int ans = -1;
            int m = q.size();
            rep(i,0,m){
                v = nxt[v][q[i]-'a'];
                int u = v;
                while(u >= 0){
                    ans = max(val[u],ans);
                    u = par[u];
                }
            }
            cout << ans << endl;
        }
        else{
            int v,x;
            cin >> v >> x;
            st[ind[v]].erase(st[ind[v]].find(a[v]));
            a[v] = x;
            st[ind[v]].insert(x);
            val[ind[v]] = *(st[ind[v]].rbegin());
        }
    }
    return 0;
}
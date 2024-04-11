#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
const long long int N = 1e6+20,mod = 1e9+7,inf = 1e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod)return a+b-mod;
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
vector<int> adj[N];
vector<pair<pll,int>> Q[N];
set<int> st[N];
int cnt[N],pre[N],n,ans[N],a[N];
inline int bs(int l,int k){
    int r = n+1,m;
    int L = l;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (pre[m]-pre[L] >= k) r = m;
        else l = m;
    }
    return r;

}
void dfs(int v){
    st[cnt[a[v]]].erase(a[v]);
    cnt[a[v]]++;
    pre[cnt[a[v]]-1]--;
    st[cnt[a[v]]].insert(a[v]);
    for (int u : adj[v]){
        dfs(u);
    }
    for (auto p : Q[v]){
        int l = p.X.X,k = p.X.Y;
        int w = bs(l,k);
        if (w > n){
            ans[p.Y] = -1;
            continue;
        }
        ans[p.Y] = *(st[w].begin());
    }
    st[cnt[a[v]]].erase(a[v]);
    cnt[a[v]]--;
    pre[cnt[a[v]]]++;
    st[cnt[a[v]]].insert(a[v]);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int q;
        cin >> n >> q;
        rep(i,0,n+1){
            st[i].clear();
            adj[i].clear();
            Q[i].clear();
            cnt[i] = 0;
            pre[i] = n;
        }
        rep(i,1,n+1){
            cin >> a[i];
        }
        rep(i,2,n+1){
            int v;
            cin >> v;
            adj[v].pb(i);
        }
        rep(i,0,q){
            int v,l,k;
            cin >> v >> l >> k;
            l--;
            Q[v].pb({{l,k},i});
        }
        dfs(1);
        rep(i,0,q) cout << ans[i] << ' ';
        cout << endl;
    }
}
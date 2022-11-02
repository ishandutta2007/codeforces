//saadddd wrong code

#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    } 
    return z; 
}
int n,par[N][20],h[N],col[N];
vector<int> ve,w,b,adj[N];
bool vis[N];
void dfs(int v,int c){
    vis[v] = 1;
    col[v] = c;
    ve.erase(lower_bound(all(ve),v));
    if (!c) w.pb(v);
    else b.pb(v);
    while (!ve.empty()){
        int sz = ve.size();
        cout << "? " << sz+1 << endl;
        cout << v << ' ';
        for (int u : ve) cout << u << ' ';
        cout << endl;
        int t;
        cin >> t;
        int d;
        cout << "? " << sz << endl;
        for (int u : ve) cout << u << ' ';
        cout << endl;
        cin >> d;
        d = t-d;
        if (!d) break;
        int l = 0,r = sz,m;
        while (r-l > 1){
            m = (l+r) >> 1;
            cout << "? " << m-l+1 << endl;
            cout << v << ' ';
            rep(i,l,m) cout << ve[i] << ' ';
            cout << endl;
            cin >> t;
            if (!t){
                l = m;
                continue;
            }
            if (m == l+1){
                r = m;
                continue;
            }
            cout << "? " << m-l << endl;
            rep(i,l,m) cout << ve[i] << ' ';
            cout << endl;
            cin >> d;
            if (t > d) r = m;
            else l = m;
        }
        adj[v].pb(ve[l]);
        h[ve[l]] = h[v]+1;
        par[ve[l]][0] = v;
        dfs(ve[l],1-c);
    }
}
int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if (h[v]-h[u] >= (1 << i)) v = par[v][i];
    }
    if (u == v) return u;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}
int main(){
  //  ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n+1) ve.pb(i);
    dfs(1,0);
    rep(j,1,20){
        rep(i,1,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    }
    if (!b.empty()){
        cout << "? " << b.size() << endl;
        for (int u : b) cout << u << ' ';
        cout << endl;
        int t;
        cin >> t;
        if (t){
            int sz = b.size();
            while (1){
                cout << "? " << sz-1 << endl;
                rep(i,0,sz-1) cout << b[i] << ' ';
                cout << endl;
                int d;
                cin >> d;
                if (d){
                    b.pop_back();
                    sz--;
                    continue;
                }
                int v = b.back();
                int l = 0,r = sz-1,m;
                while (r-l > 1){
                    m = (l+r) >> 1;
                    cout << "? " << m-l+1 << endl;
                    cout << v << ' ';
                    rep(j,l,m) cout << b[j] << ' ';
                    cout << endl;
                    int x;
                    cin >> x;
                    if (!x){
                        l = m;
                        continue;
                    }
                    if (m == l+1){
                        r = m;
                        continue;
                    }
                    cout << "? " << m-l << endl;
                    rep(j,l,m) cout << b[j] << ' ';
                    cout << endl;
                    int y;
                    cin >> y;
                    if (x > y) r = m;
                    else l = m;
                }
                int u = b[l],w = lca(u,v);
                vector<int> ans,ans2;
                while (u != w){
                    ans.pb(u);
                    u = par[u][0];
                }
                ans.pb(w);
                while (v != w){
                    ans2.pb(v);
                    v = par[v][0];
                }
                cout << "N " << ans.size()+ans2.size() << endl;
                reverse(all(ans2));
                for (int x : ans) cout << x << ' ';
                for (int x : ans2) cout << x << ' ';
                return 0;
            }
        }
        b.clear();
    }
    if (!w.empty()){
        cout << "? " << w.size() << endl;
        for (int u : w) cout << u << ' ';
        cout << endl;
        int t;
        cin >> t;
        if (t){
            int sz = w.size();
            while (1){
                cout << "? " << sz-1 << endl;
                rep(i,0,sz-1) cout << w[i] << ' ';
                cout << endl;
                int d;
                cin >> d;
                if (d){
                    w.pop_back();
                    sz--;
                    continue;
                }
                int v = w.back();
                int l = 0,r = sz-1,m;
                while (r-l > 1){
                    m = (l+r) >> 1;
                    cout << "? " << m-l+1 << endl;
                    cout << v << ' ';
                    rep(j,l,m) cout << w[j] << ' ';
                    cout << endl;
                    int x;
                    cin >> x;
                    if (!x){
                        l = m;
                        continue;
                    }
                    if (m == l+1){
                        r = m;
                        continue;
                    }
                    cout << "? " << m-l << endl;
                    rep(j,l,m) cout << w[j] << ' ';
                    cout << endl;
                    int y;
                    cin >> y;
                    if (x > y) r = m;
                    else l = m;
                }
                int u = w[l],w = lca(u,v);
                vector<int> ans,ans2;
                while (u != w){
                    ans.pb(u);
                    u = par[u][0];
                }
                ans.pb(w);
                while (v != w){
                    ans2.pb(v);
                    v = par[v][0];
                }
                cout << "N " << ans.size()+ans2.size() << endl;
                reverse(all(ans2));
                for (int x : ans) cout << x << ' ';
                for (int x : ans2) cout << x << ' ';
                return 0;
            }
        }
        w.clear();
    }
    cout << "Y ";
    vector<int> ans;
    rep(i,1,n+1) if (col[i]) ans.pb(i);
    cout << ans.size() << endl;
    for (int u : ans) cout << u << ' ';
    return 0;
}
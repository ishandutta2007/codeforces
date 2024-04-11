#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
//#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 1e5+5,mod = 1e9+7,inf = 1e9+10;
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
        k >>= 1;
    } 
    return z; 
}
vector<pll> seg[N*4];
int sz[N],h[N],ans[N];
pll par[N];
map<pll,int> mp;
void ad(int l,int r,int s,int e,pll p,int v = 1){
    if (s >= r || l >= e) return;
    if (s <= l && r <= e){
        seg[v].pb(p);
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    ad(l,m,s,e,p,u);
    ad(m,r,s,e,p,u|1);
}
int getpar(int v){
    if (par[v].X == v) return v;
    int x = getpar(par[v].X);
    h[v] = (h[par[v].X]^par[v].Y);
    return x;
}
void que(int l,int r,bool fl,int v){
    stack<pll> st;
    bool f = fl;
    if (fl){
        for (pll p : seg[v]){
            int u = getpar(p.X),w = getpar(p.Y);
            if (sz[u] > sz[w]) swap(u,w);
            st.push({u,w});
            if (u == w){
                if (h[p.X] == h[p.Y]){
                    f = 0;
                    break;
                }
                continue;
            }
            sz[w] += sz[u];
            par[u] = {w,h[p.X]^h[p.Y]^1};
        }
    }
    if (r-l == 1){
        ans[l] = f;
        while (!st.empty()){
            pll p = st.top();
            st.pop();
            if (p.X == p.Y) continue;
            sz[p.Y] -= sz[p.X];
            h[p.X] = 0;
            par[p.X] = {p.X,0};
        }
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    que(l,m,f,u);
    que(m,r,f,u|1);
    while (!st.empty()){
        pll p = st.top();
        st.pop();
        if (p.X == p.Y) continue;
        sz[p.Y] -= sz[p.X];
        h[p.X] = 0;
        par[p.X] = {p.X,0};
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,1,n+1){
        par[i] = {i,0};
        sz[i] = 1;
    }
    rep(i,1,q+1){
        int u,v;
        cin >> u >> v;
        if (u > v) swap(u,v);
        if (mp[{u,v}] == 0){
            mp[{u,v}] = i;
            continue;
        }
        ad(0,q,mp[{u,v}]-1,i-1,{u,v});
        mp[{u,v}] = 0;
    }
    for (auto p : mp){
        if (p.Y){
            ad(0,q,p.Y-1,q,p.X);
        }
    }
    que(0,q,1,1);
    rep(i,0,q) cout << ((ans[i]) ? "YES" : "NO") << endl;
    return 0;
}
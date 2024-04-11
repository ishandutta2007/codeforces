#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int h[N],vis[N],sz,a[N];
vector<int> adj[N];
void dfs(int v,int t){
    vis[v] = t;
    sz++;
    h[v]++;
    for(int u : adj[v]){
        if (!vis[u]){
            h[u] = h[v];
            dfs(u,t);
        }
    }
}
struct segment{
    int sz;
    vector<int> ve,lz;
    segment(int siz){
        sz = siz;
        ve.resize(4*sz);
        lz.resize(4*sz);
        rep(i,0,4*sz) lz[i] = 0;
    }
    void upd(int l,int r,int s,int e,int v,int x){
        if (e <= s) return;
        if (l >= s && e >= r){
            ve[v] += x*(r-l);
            lz[v] += x;
            return;
        }
        if (l >= e || s >= r) return;
        int m = (l+r)/2;
        if (lz[v]){
            ve[2*v] += (m-l)*lz[v];
            ve[2*v+1] += (r-m)*lz[v];
            lz[2*v] += lz[v];
            lz[2*v+1] += lz[v];
            lz[v] = 0;
        }
        upd(l,m,s,e,2*v,x);
        upd(m,r,s,e,2*v+1,x);
    }
    int que(int l,int r,int p,int v){
        if (r-l == 1)
            return ve[v];
        int m =(l+r)/2;
        if (lz[v]){
            ve[2*v] += lz[v]*(m-l);
            ve[2*v+1] += lz[v]*(r-m);
            lz[2*v] += lz[v];
            lz[2*v+1] += lz[v];
            lz[v] = 0;
        }
        if (p < m) return que(l,m,p,2*v);
        else return que(m,r,p,2*v+1);
    }
};
vector<segment> seg;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin >> n >> q;
    seg.reserve(20);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int t = 0;
    vis[1] = 1;
    for (int u : adj[1]){
        t++;
        dfs(u,t);
        segment s(sz);
        seg.pb(s);
        a[t] = sz;
        sz = 0;
    }
    int mx = 0;
    rep(i,2,n+1) mx = max(mx,h[i]);
    segment s(mx+1);
    a[0] = mx+1;
    seg.insert(seg.begin(),s);
    vis[1] = 0;
    rep(i,0,q){
        bool c;
        int v;
        cin >> c >> v;
        if (!c){
            int x,d;
            cin >> x >> d;
            if (v == 1){
                seg[0].upd(0,a[0],0,d+1,1,x);
                continue;
            }
            t = vis[v];
            if (d < h[v]){
                seg[t].upd(0,a[t],h[v]-d-1,h[v]+d,1,x);
                continue;
            }
            seg[0].upd(0,a[0],0,d-h[v]+1,1,x);
            seg[t].upd(0,a[t],d-h[v],h[v]+d,1,x);
        }
        else{
            if (v == 1){
                cout << seg[0].que(0,a[0],0,1) << endl;
                continue;
            }
            t = vis[v];
            int y = seg[0].que(0,a[0],h[v],1),w = seg[t].que(0,a[t],h[v]-1,1);
            cout << y+w << endl;
        }
    }
    return 0;

}
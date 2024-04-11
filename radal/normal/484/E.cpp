#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
typedef pair<ll,ll> pll;
constexpr ll N = 1e5+20,mod = 1e9+7,inf = 1e18+10,maxm = 1e6;
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
int seg[N*4][3];
int n,l[N],r[N];
pll h[N];
pair<pll,int> a[N];
vector<pll> ve;
vector<int> ch[N];
void rst(int l,int r,int v = 1){
    seg[v][0] = seg[v][1] = seg[v][2] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    rst(l,m,u);
    rst(m,r,u|1);
}

void upd(int l,int r,int p,int v = 1){
    if (r-l == 1){
        seg[v][0] = seg[v][1] = seg[v][2] = 1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,u);
    else upd(m,r,p,u|1);
    seg[v][1] = seg[u][1];
    seg[v][2] = seg[u|1][2];
    if (seg[u][1] == m-l) seg[v][1] += seg[u|1][1];
    if (seg[u|1][2] == r-m) seg[v][2] += seg[u][2];
    seg[v][0] = max({seg[v][1],seg[v][2],seg[u][0],seg[u|1][0],seg[u][2]+seg[u|1][1]});
}

void que(int l,int r,int s,int e,int v = 1){
    if (s >= r || l >= e || s >= e) return;
    if (s <= l && r <= e){
        ve.pb({v,r-l});
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    que(l,m,s,e,u);
    que(m,r,s,e,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n){
        cin >> h[i].X;
        h[i].Y = i;
    }
    sort(h,h+n);
    int q;
    cin >> q;
    rep(i,0,q){
        cin >> a[i].X.X >> a[i].X.Y >> a[i].Y;
        a[i].X.X--;
        r[i] = n;
        l[i] = 0;
    }
    rep(j,0,36){
        rep(i,0,q){
            if (r[i]-l[i] <= 1) continue;
            ch[(r[i]+l[i])/2].pb(i);
        }
        repr(i,n-1,0){
            upd(0,n,h[i].Y);
            for (int u : ch[i]){
                int L = a[u].X.X,R = a[u].X.Y;
                que(0,n,L,R);
                int cur = 0,mx = 0;
                for (pll v : ve){
                    mx = max({mx,seg[v.X][0],cur+seg[v.X][1]});
                    if (seg[v.X][1] == v.Y) cur += v.Y;
                    else cur = seg[v.X][2];
                }
                if (mx >= a[u].Y) l[u] = i;
                else r[u] = i;
                ve.clear();
            }
        }
        rst(0,n);
        rep(i,0,n) ch[i].clear();
    }
    rep(i,0,q){
        cout << h[l[i]].X << endl;
    }
}
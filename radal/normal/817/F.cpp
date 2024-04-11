#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 4e5+10,mod = 1e9+7,inf = 1e9+10;
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
int n;
int seg[N*4],lz[N*4];
pair<int,pair<ll,ll> > Q[N];
void pass(int l, int r,int v){
    if (lz[v] == -1) return;
    int u = (v << 1),m = (l+r) >> 1;
    if (lz[v] == 0){
        lz[u] = lz[v];
        lz[u|1] = lz[v];
        seg[u] = 0;
        seg[u|1] = 0;
        lz[v] = -1;
        return;
    }
    if (lz[v] == 1){
        lz[u] = lz[v];
        lz[u|1] = lz[v];
        seg[u] = m-l;
        seg[u|1] = r-m;
        lz[v] = -1;
        return;
    }
    if (lz[u] == -1){
        lz[u] = 2;
        seg[u] = m-l-seg[u];
    }
    else if (lz[u] == 0){
        lz[u] = 1;
        seg[u] = m-l;
    }
    else if (lz[u] == 1){
        lz[u] = 0;
        seg[u] = 0;
    }
    else{
        lz[u] = -1;
        seg[u] = m-l-seg[u];
    }
    if (lz[u|1] == -1){
        lz[u|1] = 2;
        seg[u|1] = r-m-seg[u|1];
    }
    else if (lz[u|1] == 0){
        lz[u|1] = 1;
        seg[u|1] = r-m;
    }
    else if (lz[u|1] == 1){
        lz[u|1] = 0;
        seg[u|1] = 0;
    }
    else{
        lz[u|1] = -1;
        seg[u|1] = r-m-seg[u|1];
    }
    lz[v] = -1;
    return;
}
void upd(int l,int r,int s,int e,int x,int v = 1){
    if (s <= l && r <= e){
        if (!x){
            seg[v] = 0;
            lz[v] = 0;
            return;
        }
        if (x == 1){
            seg[v] = r-l;
            lz[v] = 1;
            return;
        }
        seg[v] = r-l-seg[v];
        if (lz[v] == -1){
            lz[v] = 2;
            return;
        }
        if (lz[v] == 0){
            lz[v] = 1;
            return;
        }
        if (lz[v] == 1){
            lz[v] = 0;
            return;
        }
        lz[v] = -1;
        return;
    }
    if (s >= r || l >= e) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v] != -1){
        pass(l,r,v);
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = seg[u]+seg[u|1];
}
int que(int l,int r,int v){
    if (r-l == 1) return l;
    if (lz[v] != -1) pass(l,r,v);
    int m = (l+r) >> 1,u = (v << 1);
    if (seg[u] < m-l) return que(l,m,u);
    return que(m,r,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(lz,-1,sizeof lz);
    vector<ll> ve;
    cin >> n;
    ve.pb(1);
    rep(i,0,n){
        cin >> Q[i].X >> Q[i].Y.X >> Q[i].Y.Y;
        ve.pb(Q[i].Y.Y+1);
        ve.pb(Q[i].Y.X);
        ve.pb(Q[i].Y.Y);
    }
    sort(all(ve));
    ve.resize(unique(all(ve))-ve.begin());
    int sz = ve.size();
    rep(i,0,n){
        int t = Q[i].X;
        ll l = Q[i].Y.X,r = Q[i].Y.Y;
        int ind1 = lower_bound(all(ve),l)-ve.begin(),ind2 = lower_bound(all(ve),r)-ve.begin();
        if (t == 1)
            upd(0,sz,ind1,ind2+1,1);
        else if (t == 2)
            upd(0,sz,ind1,ind2+1,0);
        else
            upd(0,sz,ind1,ind2+1,2);
        cout << ve[que(0,sz,1)] << endl;
    }
    return 0;
}
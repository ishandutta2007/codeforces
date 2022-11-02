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
typedef pair<int,int> pll;
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10;
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
string s;
int hsh[N],c[N],pw[N],lz[N*4];
int nxt[N],ps[N];
pll seg[N*4];
inline int bs(int i,int j){
    int l = -1,r = n-max(i,j),m;
    while (r-l > 1){
        m = (l+r) >> 1;
        int g1,g2;
        g1 = hsh[i+m];
        g2 = hsh[j+m];
        if (i){
            g1 -= 1ll*hsh[i-1]*pw[m+1]%mod;
            if(g1 < 0) g1 += mod;
        }
        if (j){
            g2 -= 1ll*hsh[j-1]*pw[m+1]%mod;
            if (g2 < 0) g2 += mod;
        }
        if (g1 == g2) l = m;
        else r = m;
    }
    return r;
}
inline bool cmp(int i,int j){
    int x = bs(i,j);
    if (max(i,j)+x >= n)
        return (i > j);
    return (s[i+x] < s[j+x]);
}
inline void pass(int v){
    if (!lz[v]) return;
    int u = (v << 1);
    lz[u] += lz[v];
    lz[u|1] += lz[v];
    seg[u].X += lz[v];
    seg[u|1].X += lz[v];
    lz[v] = 0;
}
void upd(int l,int r,int s,int e,int x,int v = 1){
    if (s >= e || l >= e || s >= r) return;
    if (s <= l && r <= e){
        lz[v] += x;
        seg[v].X += x;
        return;
    }
    pass(v);
    int u = (v << 1),m = (l+r) >> 1;
    if (e <= m) upd(l,m,s,e,x,u);
    else if (s >= m) upd(m,r,s,e,x,u|1);
    else{
        upd(l,m,s,m,x,u);
        upd(m,r,m,e,x,u|1);
    }
    if (seg[u].X == seg[u|1].X) seg[v] = {seg[u].X,seg[u].Y+seg[u|1].Y};
    else seg[v] = min(seg[u],seg[u|1]);
}
pll que(int l,int r,int s,int e,int v = 1){
    if (s >= e || l >= e || s >= r) return {inf,inf};
    if (s == l && r == e) return seg[v];
    pll p1,p2;
    pass(v);
    int m = (l+r) >> 1,u = (v << 1);
    if (e <= m) return que(l,m,s,e,u);
    if (s >= m) return que(m,r,s,e,u|1);
    p1 = que(l,m,s,m,u);
    p2 = que(m,r,m,e,u|1);
    if (p1.X != p2.X || p1.X == inf) return min(p1,p2);
    return {p1.X,p1.Y+p2.Y};
}
void rst(int l,int r,int v = 1){
    seg[v] = {0,r-l};
    lz[v] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    rst(l,m,u);
    rst(m,r,u|1);
}
inline int bs(int L){
    int l = nxt[L+1]-1, r = n+1,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (que(0,n+1,L,m).X >= 0) l = m;
        else r = m;
    }
    return l;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    vector<int> ve;
    pw[0] = 1;
    rst(0,n+1);
    rep(i,0,n){
        pw[i+1] = 1ll*257*pw[i]%mod;
        hsh[i] = (s[i]-'('+1);
        if (i)
            hsh[i] = mkay(1ll*hsh[i-1]*257%mod,hsh[i]);
        ve.pb(i);
    }
    sort(ve.begin(),ve.end(),cmp);
    rep(i,1,n)
        c[i] = bs(ve[i],ve[i-1]);
    upd(0,n+1,n,n+1,-inf);
    nxt[n] = n;
    repr(i,n-1,0){
        if (s[i] == '('){
            upd(0,n+1,i,n+1,1);
            nxt[i] = bs(i);
        }
        else{
            upd(0,n+1,i,n+1,-1);
            nxt[i] = i;
        }
    }
    rst(0,n+1);
    rep(i,0,n){
        if (s[i] == '(') ps[i] = 1;
        else ps[i] = -1;
        if (i) ps[i] += ps[i-1];
        upd(0,n+1,i,i+1,ps[i]);
    }
    int h = 0;
    if (ve[0]) h = ps[ve[0]-1]; 
    upd(0,n+1,0,n+1,-h);
    ll ans = 0;
    pll p1 = que(0,n+1,ve[0],nxt[ve[0]]);
    if(p1.X == 0) ans += p1.Y;
    upd(0,n+1,0,n+1,h);
    rep(i,1,n){
        int g = 0;
        if (ve[i]) g = ps[ve[i]-1];
        upd(0,n+1,0,n+1,-g);
        pll p = que(0,n+1,c[i]+ve[i],nxt[ve[i]]);
        if (p.X == 0) ans += p.Y;
        upd(0,n+1,0,n+1,g);
    }
    cout << ans;
}
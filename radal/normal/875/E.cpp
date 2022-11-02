#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e9+10,sq = 32000;
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
int n,r[N];
bool seg[N*4][2];
int sg[N*4][2];
vector<int> ve;
void rst(int l,int r ,int v = 1){
    seg[v][0] = 0;
    seg[v][1] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    rst(l,m,u);
    rst(m,r,u|1);
}
void build(int l,int r,int v = 1){
    if (r-l == 1){
        sg[v][0] = ve[l];
        sg[v][1] = ve[l];
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    sg[v][0] = min(sg[u][0],sg[u|1][0]);
    sg[v][1] = max(sg[u][1],sg[u|1][1]);
}
int src(int l,int r,int p,int d,int v = 1){
    if (ve[p]-sg[v][0] <= d && sg[v][1]-ve[p] <= d) return r;
    if (r-l == 1) return l;
    int m = (l+r) >> 1,u = (v << 1);
    if (m <= p) return src(m,r,p,d,u|1);
    int x = src(l,m,p,d,u);
    if (x != m) return x;
    return src(m,r,p,d,u|1);
}
bool que(int l,int r,int p,bool f,int v = 1){
    if (seg[v][f]) return 1;
    if (r-l == 1) return 0;
    int m = (l+r) >> 1;
    if (p >= m) return que(m,r,p,f,2*v+1);
    else return que(l,m,p,f,2*v);
}
void upd(int l,int r,int s,int e,bool f,int v = 1){
    if (e <= s) return;
    if (s <= l && r <= e){
        seg[v][f] = 1;
        return;
    }
    if (r <= s || e <= l) return;
    if (seg[v][f]) return;
    int m = (l+r) >> 1,u = (v << 1);
    upd(l,m,s,e,f,u);
    upd(m,r,s,e,f,u|1);
}
inline bool check(int d){
    rst(0,n);
    r[n-1] = n;
    repr(i,n-2,0){
        r[i] = src(0,n,i,d);
    }
    upd(0,n,0,1,0);
    upd(0,n,1,r[0],1);
    if (r[0] == n) return 1;
    rep(i,1,n-1){
        if (que(0,n,i,0)){
            if (r[i] == n) return 1;
            upd(0,n,i+1,r[i],1);

        }
        if (que(0,n,i,1)){
            if (r[i] == n) return 1;
            upd(0,n,i+1,r[i],0);
        }
    }
    return 0;
}
inline int bs(){
    int l = abs(ve[1]-ve[0])-1,r = inf,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    return r;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int s,t;
    cin >> n >> s >> t;
    ve.pb(s);
    ve.pb(t);
    rep(i,0,n){
        int x;
        cin >> x;
        ve.pb(x);
    }
    n += 2;
    build(0,n);
    cout << bs();
    return 0 ;
}
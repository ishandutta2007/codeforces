#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 2e6+20,mod = 1e9+7 ,inf = 1e9+10;
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
int seg[N*4],lz[N*4],a[N],sz;
string s[N];

void build(int l,int r,int v = 1){
    seg[v] = inf;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}

inline void pass(int v){
    if (!lz[v]) return;
    int u = (v << 1);
    lz[u] += lz[v];
    seg[u] += lz[v];
    lz[u|1] += lz[v];
    seg[u|1] += lz[v];
    lz[v] = 0;
}

void upd(int l,int r,int p,int x,int v = 1){
    if (r-l == 1){
        seg[v] = x;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    pass(v);
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}

void upd2(int l,int r,int s,int e,int x,int v = 1){
    if (s >= r || l >= e) return;
    if (s <= l && r <= e){
        seg[v] += x;
        lz[v] += x;
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
    pass(v);
    upd2(l,m,s,e,x,u);
    upd2(m,r,s,e,x,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}

int que(int l,int r,int s,int e,int v = 1){
    if (s >= r || l >= e) return inf;
    if (s <= l && r <= e) return seg[v];
    pass(v);
    int m = (l+r) >> 1,u = (v <<1);
    return min(que(l,m,s,e,u),que(m,r,s,e,u|1));
}
int f(int i,int j){
    if (i < 0) return sz;
    repr(k,sz,1){
        bool fl = 0;
        rep(g,0,k){
            if (s[j][g] != s[i][sz-k+g]){
                fl = 1;
                break;
            }
        }
        if (!fl) return sz-k;
    }
    return sz;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> s[i];
        sz = s[i].size();
        rep(j,0,sz)
            if (s[i][j] == '1')
                a[i] += (1 << j);
    }
    int lim = (1 << sz);
    build(0,lim+1);
    upd(0,lim+1,lim,sz);
    rep(i,1,n){
        int x = f(i-1,i);
        int l = 0,r = lim+1;
        int calc = inf;
        rep(j,0,sz+1){
            if (j){
                l = 0;
                rep(g,0,j){
                    if(s[i][g] == '1'){
                        l += (1 << (sz-j+g));
                    }
                    r = l+(1 << (sz-j));
                }
            }
            calc = min(calc,sz-j+que(0,lim+1,l,r));
        }
        seg[1] += x;
        lz[1] += x;
        upd(0,lim+1,a[i-1],calc);
    }
    cout << seg[1];
}
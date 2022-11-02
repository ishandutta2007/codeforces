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
constexpr int N = 4e5+20,mod = 1e9+7,inf = 1e9+10,base = 271;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int p){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    } 
    return z; 
}
int pw[N],ps[N];
int n,q,k,seg[N*4],lz[N*4];
string s;
void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v] = s[l]-'0'+1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = mkay(seg[u],1ll*seg[u|1]*pw[m-l]%mod);
}
void upd(int l,int r,int s,int e,int x,int v = 1){
    if (l >= e || s >= r) return;
    if (s <= l && r <= e){
        seg[v] = 1ll*x*ps[r-l-1]%mod;
        lz[v] = x;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] = lz[v];
        lz[u|1] = lz[v];
        seg[u] = 1ll*lz[v]*ps[m-l-1]%mod;
        seg[u|1] = 1ll*lz[v]*ps[r-m-1]%mod;
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = mkay(seg[u],1ll*seg[u|1]*pw[m-l]%mod);
}
int que(int l,int r,int s,int e,int v = 1){
    if (l >= e || s >= r) return 0;
    if (s <= l && r <= e) return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] = lz[v];
        lz[u|1] = lz[v];
        seg[u] = 1ll*lz[v]*ps[m-l-1]%mod;
        seg[u|1] = 1ll*lz[v]*ps[r-m-1]%mod;
        lz[v] = 0;
    }
    if (e <= m) return que(l,m,s,e,u);
    if (m <= s) return que(m,r,s,e,u|1);
    return mkay(que(l,m,s,m,u),1ll*que(m,r,m,e,u|1)*pw[m-s]%mod);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> q >> k >> s;
    pw[0] = ps[0] = 1;
    rep(i,1,n+1){
        pw[i] = 1ll*base*pw[i-1]%mod;
        ps[i] = mkay(ps[i-1],pw[i]);
    }
    build(0,n);
    q += k;
    while (q--){
        int ty,l,r,c;
        cin >> ty >> l >> r >> c;
        l--;
        if (ty == 1){
            c++;
            upd(0,n,l,r,c);
        }
        else{
            int hsh1 = que(0,n,l,r-c),hsh2 = que(0,n,l+c,r);
            cout << ((hsh1 == hsh2) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
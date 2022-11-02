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
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10;
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
int seg[N*4],a[N];
void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v] = a[l];
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}
int que(int l,int r,int s,int e,int v = 1){
    if (s >= r || l >= e) return 0;
    if (s <= l && r <= e) return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    return max(que(l,m,s,e,u),que(m,r,s,e,u|1));
}
inline void solve(){
    int m,n;
    cin >> m >> n;
    rep(i,0,n) cin >> a[i];
    build(0,n,1);
    int q;
    cin >> q;
    while (q--){
        int x,y,z,w,k;
        cin >> x >> y >> z >> w >> k;
        swap(x,y);
        swap(z,w);
        x--;
        z--;
        if (x%k != z%k || y%k != w%k){
            cout << "NO" << endl;
            continue;
        }
        if (m%k >= y%k){
            y = m-(m%k-y%k);
            w = y;
        }
        else{
            y = m-k-m%k+y%k;
            w = y;
        }
        if (x > z) swap(x,z);
        int mx = que(0,n,x,z+1);
        if (mx >= y) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
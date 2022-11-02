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
constexpr int N = 3e5+10,mod = 998244353,inf = 1e9+10;
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
int a[N],pr[N],lz[N*4];
pll seg[N*4];
void build(int l,int r,int v){
    if (r-l == 1){
        seg[v] = {0,l};
        lz[v] = 0;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    lz[v] = 0;
    seg[v] = max(seg[u],seg[u|1]);
}
void upd(int l,int r,int s,int e,int x,int v = 1){
    if (s <= l && r <= e){
        seg[v].X += x;
        lz[v] += x;
        return;
    }
    if (s >= r || l >= e) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u].X += lz[v];
        seg[u|1].X += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}
pll que(int l,int r,int s,int e,int v = 1){
    if (s >= r || l >= e) return {-inf,-1};
    if (s <= l && r <= e) return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u].X += lz[v];
        seg[u|1].X += lz[v];
        lz[v] = 0;
    }
    return max(que(l,m,s,e,u),que(m,r,s,e,u|1));

}
inline void solve(){
    int n;
    cin >> n;
    vector<int> ve,ve2;
    rep(i,0,n){
        cin >> a[i];
        ve.pb(a[i]);
    }
    reverse(all(ve));
    int cnt = 0;
    while (!ve.empty() && !ve.back()){
        ve.pop_back();
        cnt++;
    }
    ve.pb(cnt);
    while (ve.size() > 2){
        ve2.clear();
        int n  = ve.size();
        rep(i,0,n-2){
            ve2.pb(ve[i]-ve[i+1]);
        }
        if (ve[n-1]) ve2.pb(ve[n-2]);
        sort(all(ve2));
        reverse(all(ve2));
        int t = 0;
        while (!ve2.empty() && !ve2.back()){
            ve2.pop_back();
            t++;
        }
        ve2.pb(t+max(0,cnt-1));
        cnt = ve2.back();
        ve = ve2;
    }
    if (ve.size() == 1){
        cout << 0 << endl;
        return;
    }
    cout << ve[0] << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
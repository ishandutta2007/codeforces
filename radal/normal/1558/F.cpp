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
constexpr int N = 2e5+10,mod = 1e9+7,inf = 1e9+10;
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
int seg[N*4],a[N],lz[N*4],ind[N];
void build(int l,int r,int v){
    lz[v] = 0;
    if (r-l == 1){
        seg[v] = l%2-l;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}
void upd(int l,int r,int s,int e,int x,int v = 1){
    if (l >= e || s >= r || s >= e) return;
    if (s <= l && r <= e){
        seg[v] += x;
        lz[v] += x;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}
int que(int l,int r,int s,int e,int v = 1){
    if (l >= e || s >= r || s >= e) return -inf;
    if (s <= l && r <= e)
        return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[v] = 0;
    }
    return max(que(l,m,s,e,u),que(m,r,s,e,u|1));
}
inline void solve(){
    cin >> n;
    set<int> st;
    rep(i,1,n+1){
        st.insert(i);
        cin >> a[i];
        ind[a[i]] = i;
    }
    build(0,n+1,1);
    int ans = 0,mi = n+1;
    repr(i,n,2){
        mi = min(mi,ind[i]);
        upd(0,n+1,ind[i],n+1,2);
        upd(0,n+1,ind[i],ind[i]+1,-inf);
        st.erase(ind[i]);
        int m = (*st.rbegin());
        ans = max(ans,i-1+que(0,n+1,mi,m+1));
    }
    cout << ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
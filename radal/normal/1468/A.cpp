#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
//#pragma GCC optimize("unroll-loops")
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
constexpr int N = 5e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 18)+10;
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
int n, a[N],seg[N*4],L[N];
void build (int l,int r,int v = 1){
    seg[v] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}
void upd(int l,int r,int p,int x,int v = 1){
    if (r-l == 1){
        seg[v] = x;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}
int que(int l,int r,int s,int e,int v = 1){
    if (s <= l && r <= e) return seg[v];
    if (s >= r || l >= e) return 0;
    int m = (l+r) >> 1,u = (v << 1);
    return max(que(l,m,s,e,u),que(m,r,s,e,u|1));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<pll> ve;
        rep(i,0,n){
            cin >> a[i];
            ve.pb({a[i],i});
        }
        sort(ve.begin(),ve.end());
        stack<int> st;
        rep(i,0,n){
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            if (st.empty()) L[i] = -1;
            else L[i] = st.top();
            st.push(i);
        }
        int ans = 1;
        rep(i,0,n){
            int j = ve[i].Y,cur;
            if (L[j] == -1){
                cur = que(0,n,0,j+1)+1;
                ans = max(ans,cur);
                upd(0,n,j,cur);
                continue;
            }
            cur = max(que(0,n,0,j+1)+1,que(0,n,0,L[j]+1)+2);
            ans = max(ans,cur);
            upd(0,n,j,cur);
        }
        cout << ans << endl;
        build(0,n);
    }
}
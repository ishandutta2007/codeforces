#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
int a[N],r[N][2];
pll seg[N*4][2];
void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v][0] = seg[v][1] = {a[l],l};
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v][1] = max(seg[u][1],seg[u|1][1]);
    seg[v][0] = min(seg[u][0],seg[u|1][0]);
}
pll que(int l,int r,int s,int e,bool f,int v = 1){
    if (s <= l && r <= e) return seg[v][f];
    if (s >= e || s >= r || l >= e){
        if (f) return {0,0};
        return {inf,0};
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (f) return max(que(l,m,s,e,f,u),que(m,r,s,e,f,u|1));
    return min(que(l,m,s,e,f,u),que(m,r,s,e,f,u|1));
}
inline void solve(){
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    build(0,n);
    stack<int> st;
    repr(i,n-1,0){
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        if (st.empty())  r[i][1] = n;
        else r[i][1] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    repr(i,n-1,0){
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        if (st.empty()) r[i][0] = n;
        else r[i][0] = st.top();
        st.push(i);
    }
    int cur = 0,ans = 0;
    while(cur < n-1){
        ans++;
        pll p;
        if (a[cur] > a[cur+1]){
            p = que(0,n,cur,r[cur][1],0);
        }
        else
            p = que(0,n,cur,r[cur][0],1);
        cur = p.Y;
    }
    cout << ans << endl;
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int T = 1;
   cin >> T;
   while (T--){
       solve();
   }
}
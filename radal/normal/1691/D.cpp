#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4")
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
constexpr int N = 2e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
int a[N],r[N],l[N],lg[N];
ll pre[N],sp[N][20][2];
inline ll rmq(int l,int r,bool f){
    int t = lg[r-l];
    if (f){
        return max(sp[r-1][t][1],sp[l+(1 << t)-1][t][1]);
    }
    return min(sp[r-1][t][0],sp[l+(1 << t)-1][t][0]);
}
inline void solve(){
    int n;
    cin >> n;
    int mx = -inf;
    lg[1] = 0;
    rep(i,0,n){
        cin >> a[i];
        lg[i+2] = lg[(i+2)/2]+1;
    }
    rep(i,0,n){
        if (!i){
            pre[i] = a[i];
            sp[i][0][0] = sp[i][0][1] = pre[i];
            mx = a[i];
            continue;
        }
        if (min(a[i],a[i-1]) > 0 || pre[i-1]+a[i] > max(mx,a[i])){
            cout << "NO" << endl;
            return;
        }
        pre[i] = pre[i-1]+a[i];
        sp[i][0][0] = sp[i][0][1] = pre[i];
        mx = max(mx,a[i]);
    }
    stack<int> st;
    rep(i,0,n){
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        if (st.empty()) l[i] = -1;
        else l[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    repr(i,n-1,0){
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty()) r[i] = n;
        else r[i] = st.top();
        st.push(i);
    }
    rep(j,1,20){
        rep(i,(1 << j)-1,n){
            sp[i][j][0] = min(sp[i][j-1][0],sp[i-(1 << (j-1))][j-1][0]);
            sp[i][j][1] = max(sp[i][j-1][1],sp[i-(1 << (j-1))][j-1][1]);
        }
    }
    rep(i,0,n){
        ll x,y = rmq(i,r[i],1);
        if (l[i] != -1)
            x = rmq(l[i],i,0);
        else{
            if (i-l[i] == 1) x = 0;
            else x = rmq(l[i]+1,i,0);
            if (x > 0) x = 0;
        }
        if (y-x > a[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}
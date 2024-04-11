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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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
int r[N],l[N],a[N];
ll pre[N][2];
inline void solve(){
    int n,m;
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n-1){
        r[i] = max(0,a[i]-a[i+1]);
        pre[i][0] = r[i];
        if (i) pre[i][0] += pre[i-1][0];
    }
    rep(i,1,n){
        l[i] = max(0,a[i]-a[i-1]);
        pre[i][1] = l[i];
        if (i > 1) pre[i][1] += pre[i-1][1];
    }
    rep(i,0,m){
        int s,t;
        cin >> s >> t;
        s--;
        t--;
        if (s < t){
            if (s) cout << pre[t-1][0]-pre[s-1][0] << endl;
            else cout << pre[t-1][0] << endl;
            continue;
        }
        cout << pre[s][1]-pre[t][1] << endl;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
//    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
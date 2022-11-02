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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,sq = 500;
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
int a[N];
ll suf[N],pre[N];
void solve(){
    int n;
    cin >> n;
    rep(i,0,n)
        cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < n-1; i += 2){
        ans += max({0,a[i+1]-a[i]+1,a[i-1]-a[i]+1});
    }
    if (n&1){
        cout << ans << endl;
        return ;
    }
    suf[n] = 0;
    for (int i = n-2; i > 0; i -= 2){
        suf[i] = suf[i+2]+max({0,a[i+1]-a[i]+1,a[i-1]-a[i]+1});
    }
    for (int i = 1;  i < n-1; i += 2){
        pre[i] = max({0,a[i+1]-a[i]+1,a[i-1]-a[i]+1});
        if (i > 1) pre[i] += pre[i-2];
    }
    ans = min(pre[n-3],suf[2]);
    for (int i = 4; i < n-1; i += 2)
        ans = min(ans,suf[i]+pre[i-3]);
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
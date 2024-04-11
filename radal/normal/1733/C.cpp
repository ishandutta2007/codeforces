#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
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
constexpr int N = 1e5+15,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
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
void solve(){
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    if (n == 1){
        cout << 0 << endl;
        return;
    }
    vector<pll> ans;
    int j = -1;
    repr(i,n-1,0){
        if (a[i]%2 == a[0]%2){
            j = i;
            break;
        }
    }
    rep(i,0,j){
        if (a[i]%2 != a[j]%2) continue;
        ans.pb({i,j});
        a[i] = a[j];
    }
    rep(i,1,n){
        if (a[i]%2 != a[j]%2){
            ans.pb({0,i});
            a[i] = a[0];
            continue;
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) cout << p.X+1 << ' ' << p.Y+1 << endl;
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
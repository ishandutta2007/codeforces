#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 2e5+15,mod = 998244353,inf = 1e9+10;
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

int s[N],a[N];
inline void solve(){
    int n,k;
    cin >> n >> k;
    rep(i,n-k,n){
        cin >> s[i];
    }
    if (k == 1){
        cout << "YES" << endl;
        return;
    }
    rep(i,n-k+1,n){
        a[i] = s[i]-s[i-1];
        if (i > n-k+1 && a[i] < a[i-1]){
            cout << "NO" << endl;
            return;
        }
    }
    if (1ll*(n-k+1)*a[n-k+1] < s[n-k]*1ll){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
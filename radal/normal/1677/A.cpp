#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 5e3+20,mod = 1e9+7,inf = 1e9+10;
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
ll suf[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        rep(i,0,n){
            suf[i][n] = 0;
            repr(j,n-1,0){
                suf[i][j] = suf[i][j+1];
                if (a[i] > a[j])
                    suf[i][j]++;
            }
        }
        rep(j,0,n+1){
            rep(i,1,n)
                suf[i][j] += suf[i-1][j];
        }
        ll ans = 0;
        rep(i,0,n){
            rep(j,i+2,n){
                if (a[j] < a[i]) continue;
                ans += suf[j-1][j+1]-suf[i][j+1];
            }
        }
        cout << ans << endl;
    }

}
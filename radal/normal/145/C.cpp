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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10,base = 233;
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
map<int,int> mp;
int dp[N],a[N],fac[N],inv[N];
bool lucky(int v){
    while (v){
        int d = v%10;
        if (d != 4 && d != 7) return 0;
        v /= 10;
    }
    return 1;
}
inline int c(int r,int n){
    if (r > n || r < 0) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int n,t = 0,k;
   cin >> n >> k;
   fac[0] = inv[0] = 1;
   rep (i,0,n){
       cin >> a[i];
       fac[i+1] = 1ll*(i+1)*fac[i]%mod;
       inv[i+1] = poww(fac[i+1],mod-2);
       if (lucky(a[i])) mp[a[i]]++;
       else t++;
   }
   vector<int> ve;
   for (auto u : mp){
       ve.pb(u.Y);
   }
   dp[0] = 1;
   int sz = ve.size();
   rep(i,0,sz){
       repr(j,i+1,1){
           dp[j] = mkay(dp[j],1ll*dp[j-1]*ve[i]%mod);
       }
   }
   int ans = 0;
   rep(i,0,sz+1){
       if (i > k) break;
       ans = mkay(ans,1ll*dp[i]*c(k-i,t)%mod);
   }
   cout << ans;
   return 0;
}
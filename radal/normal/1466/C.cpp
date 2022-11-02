#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
vector<pll> ve;
int dp[N];
int main(){
   // ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> s;
        n = s.size();
        dp[0] = 0;
        bool f1 = 0,f2 = 0;
        rep(i,1,n){
            if (s[i-1] == s[i] && !f1){
                dp[i] = dp[i-1]+1;
                f1 = 1;
                f2 = 0;
            }
            else if (i > 1 && s[i-2] == s[i] && !f2){
                dp[i] = dp[i-1]+1;
                f2 = f1;
                f1 = 1;
            }
            else{
                dp[i] = dp[i-1];
                f2 = f1;
                f1 = 0;
            }
        }
        cout << dp[n-1] << endl;
    }
    return 0;
}
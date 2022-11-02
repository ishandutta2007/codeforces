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
constexpr int N = 1e6+15,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (k == 1) return a;
    int r = poww(a,k/2);
    if (k&1) return 1ll*a*r%mod*r%mod;
    return 1ll*r*r%mod; 
}

int dp[N],cnt[N],pw[N];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); 
    int T;
    cin >> T;
    pw[0] = 1;
    rep(i,1,N) pw[i] = mkay(pw[i-1],pw[i-1]);
    while (T--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        dp[n] = 1;
        int s = 1,lm = n;
        repr(i,n-1,2){
            while (lm >= 2*i){
                s -= dp[lm];
                lm--;
                if (s < 0) s += mod;
            }
            dp[i] = s;
            s = mkay(s,dp[i]);
        }
        int inv = poww(pw[n],mod-2);
        rep(i,1,n+1){
            cout << 1ll*dp[i]*inv%mod*pw[i/2+1]%mod << endl;
        }
    }
    return 0;
}
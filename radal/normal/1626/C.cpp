#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 7e5+20,mod = 1e9+7,inf = 1e18,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
int k[N],h[N];
ll dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,1,n+1) cin >> k[i];
        rep(i,1,n+1){
            cin >> h[i];
            dp[i] = inf*2;
        }
        rep(i,1,n+1){
            int p1 = i-1,mi = k[i]-h[i]+1;
            while (p1 >= 0){
                if (k[p1]+1 <= mi){
                    int j = mi-k[p1];
                    dp[i]= min(dp[i],dp[p1]+1ll*(k[i]-k[p1]-j+2)*(k[i]-k[p1]-j+1)/2);
                }
                mi = min(mi,k[p1]-h[p1]+1);
                p1--;
            }
        }
        cout << dp[n] << endl;
    }
}
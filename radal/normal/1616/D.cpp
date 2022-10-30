#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
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
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N];
int l[N];
int dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n,x;
        cin >> n;
        rep(i,0,n) cin >> a[i]; 
        cin >> x;
        int cnt[2] = {0,0};
        cnt[0] += (a[0] >= x);
        rep(i,1,n){
            if (a[i]+a[i-1] < 2*x){
                l[i] = i;
                continue;
            }
            if (i == 1){
                l[i] = 0;
                continue;
            }
            if (a[i]+a[i-1]+a[i-2] < 3*x){
                l[i] = i-1;
                continue;
            }
            l[i] = l[i-2];
        }
        rep(i,1,n) l[i] = max(l[i],l[i-1]);
        dp[0] = 1;
        rep(i,1,n){
            if (l[i] > 1) dp[i] = max(dp[i-1],dp[l[i]-2]+i-l[i]+1);
            else{
                if (!l[i]) dp[i] = i+1;
                else dp[i] = i;
            }
        }
        cout << dp[n-1] << endl;
    }
}
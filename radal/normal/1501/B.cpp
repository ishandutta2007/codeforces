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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=2e5+10,mod = 2e18,inf=1e18;
const long double eps = 0.0001;
ll a[N],dp[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        if (a[n-1]) dp[n-1] = n-1;
        else dp[n-1] = -1;
        repr(i,n-2,0){
            if (dp[i+1] == -1){
                if (a[i]) dp[i] = i;
                else dp[i] = -1;
                continue;
            }
            if (a[dp[i+1]] - (dp[i+1]-i) > a[i]) dp[i] = dp[i+1];
            else{
                if (!a[i]) dp[i] = -1;
                else dp[i] = i;
            }
        }
        rep(i,0,n) cout << ((dp[i] == -1) ? 0 : 1) << ' ';
        cout << endl;
    }
}
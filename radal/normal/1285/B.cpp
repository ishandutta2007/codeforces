#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e5+10;
ll a[N],b[N],dp[N];
int main(){ 
    ios:: sync_with_stdio(false); 
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        ll sum=0;
        rep (i,0,n){
            cin >> a[i];
            sum += a[i];
        }
        dp[0] = a[0];
        rep(i,1,n-1) dp[i] = max(a[i], dp[i-1]+a[i]);
        bool f=1;
        dp[n-1] = 0;
        ll s=0;
        repr (i,n-1,1){
            s+=a[i];
            dp[n-1]=max(dp[n-1],s);
        }
        rep (i,0,n){
            if (dp[i] >= sum){
                f=0;
                break;
            }
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
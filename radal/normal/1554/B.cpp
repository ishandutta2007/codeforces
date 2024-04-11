#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        rep(i,1,n+1) cin >> a[i];
        ll ans = 1ll*n*(n-1)-1ll*k*(a[n-1]|a[n]);
        repr(i,n,2){
            if (1ll*i*n <= ans) continue;
            repr(j,i-1,1){
                if (1ll*i*j < ans) continue;
                ans = max(ans,1ll*i*j-1ll*k*(a[i]|a[j]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
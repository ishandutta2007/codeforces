#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=4e18,maxk = 1e5+20;
const long double eps = 0.0001;
ll a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        if (n%2 == 0){
            int ans = k%n;
            if (ans) cout << ans << endl;
            else cout << n << endl;
            continue;
        }
        if (k == 1){
            cout << 1 << endl;
            continue;
        }
        ll x = n/2;
        ll ans = (k+(k-1)/x)%n;
        if (ans) cout<<ans << endl;
        else cout << n << endl;
    }
    return 0;
}
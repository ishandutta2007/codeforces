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
const long long int N=2e5+20,mod = 1e9+7,inf=1e12,maxq = 5e5+30,maxm = 3e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
bool prime(ll n){
    ll s = sqrt(n);
    rep(i,2,s+1){
        if (n%i == 0) return 0;
    }
    return 1;
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        ll d,a;
        cin >> d;
        if (!d){
            cout << 6 << endl;
            continue;
        }
        rep(i,d+1,10000+d){
            if (prime(i)){
                a = i;
                break;
            }
        }
        ll ans = a*a*a;
        bool f = 0;
        rep(i,a+d,100000+a+d){
            if (prime(i)){
                cout << min(ans,(a)*i) << endl;
                f = 1;
                break;
            }
        }
        if (f) continue;
        cout << ans << endl;

    }
    return 0;
}
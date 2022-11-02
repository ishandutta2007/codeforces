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
int main(){
    int T;
    cin >> T;
    while (T--){
        ll a,b;
        cin >> a >> b;
        if (b > a){
            cout << 1 << endl;
            continue;
        }
        if (a == b){
            cout << 2 << endl;
            continue;
        }
        ll ans = inf;
        rep(i,b,b+100000){
            ll cnt = i-b;
            ll c = a;
            if (i == 1)  continue;
            while (c){
                c /= i;
                cnt++;
            }
            ans = min(ans,cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
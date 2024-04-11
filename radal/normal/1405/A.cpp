#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=1e4+10;
ll ans[N];
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        ll a[n];
        rep (i,0,n){
            cin >> a[i];
        }
        reverse(a,a+n);
        rep (i,0,n) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}
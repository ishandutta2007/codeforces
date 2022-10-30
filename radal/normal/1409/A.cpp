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
const int N=1e3+30;
ll a[N];
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll t,b,c;
        cin >> b >> c;
        t= abs(b-c);
        ll ans=t/10;
        if (t%10) ans++;
        cout << ans << endl;

    }
    return 0;
}
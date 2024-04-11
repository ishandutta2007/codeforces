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
ll GCD (ll a,ll b){
    if (b > a) swap (a,b);
    if (!b) return a;
    return GCD(b,a%b);
}
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n,t0=0,t1=0;
        cin >> n;
        ll a[n];
        rep (i,0,n){
            cin >> a[i];
            if (a[i]) t1++;
            else t0++;
        }
        if (t1 >= n/2+(n/2)%2 || t0 < n/2){
            cout << n/2+(n/2)%2 << endl;
            rep (i,0,n/2+(n/2)%2){
                cout << 1 << ' ';
            }
            cout << endl;
        }
        else {
            cout << n/2 << endl;
            rep (i,0,n/2){
                cout << 0 << ' ';
            }
            cout << endl;
        }

    }
    return 0;
}
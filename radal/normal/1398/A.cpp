#include <bits/stdc++.h>
#define ll long long int
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
#define endl '\n'
using namespace std;
int main(){
    ll t;
    cin >> t;
    rep (j,0,t){
        ll n;
        cin >> n;
        ll a[n];
        rep (i,0,n){
            cin >> a[i];
        }
        if (a[0] + a[1] > a[n-1]){
            cout << -1 << endl;
            continue;
        }
        cout << 1 << " " << 2 << " " << n << endl;
    }
}
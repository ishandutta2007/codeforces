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
const long long int N=2e6+30;
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n,t=0;
        cin >> n;
        bool L[n],R[n];
        ll a[n];
        rep (i,0,n) cin >> a[i];
        ll p1=1;
        while (p1 < n && a[p1] > a[p1-1]){
            p1++;
        }
        while (p1<n && a[p1] < a[p1-1]) p1++;
        if (p1 == n){
            cout << "YES" << endl;
            continue;
        }
        L[0] = 1;
        rep(i,1,n){
            L[i] = ((a[i] >= i) & L[i-1]);
        }
        R[n-1] = 1;
        repr(i,n-2,0){
            R[i] = ((a[i] >= n-i-1) & R[i+1]);
        }
        if (R[0] || L[n-1]){
            cout << "YES" << endl;
            continue;
        }
        bool f=0;
        rep (i,1,n-1){
            if (L[i-1] && R[i+1] && a[i] > max(i-1,n-i-2)){
                f = 1;
                break;
            }
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
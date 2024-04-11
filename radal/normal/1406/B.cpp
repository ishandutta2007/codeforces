#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const int N=2e5+30;
ll a[N];
int main(){
    int T;
    cin >> T;
    while (T--){       
        ll n;
        cin >> n;
        rep(i,0,n){
            ll x;
            cin >> a[i];
        }
        sort(a,a+n);
        ll ans=1;
        rep(i,1,6) ans*=a[n-i];
        ll z=a[0];
        rep(i,1,5){
            z*=a[n-i];
        }
        ans = max(ans,z);
        z=a[0]*a[1];
        rep(i,1,4){
            z *= a[n-i];
        }
        ans = max(ans,z);
        z=a[0]*a[1]*a[2];
        rep(i,1,3){
            z *= a[n-i];
        }
        ans = max(ans,z);
        z=a[0]*a[1]*a[2]*a[3];
        rep(i,1,2){
            z *= a[n-i];
        }
        ans = max(ans,z);
        cout << ans << endl;
    }
    return 0;
}
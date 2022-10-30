#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << ": " << x << endl;
#define X first
#define Y second
#define mp make_pair
using namespace std; 
const long long int N=1e6+30;
int main(){
	ios_base::sync_with_stdio(false);	cout.tie(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n,k;
        cin >> n >> k;
        ll a[n];
        rep (i,0,n) cin >> a[i];
        sort(a,a+n);
        ll ans=0;
        rep (i,1,n){
            ans+=(k-a[i])/a[0];
        }
        cout << ans << endl;
    }
    return 0;
}
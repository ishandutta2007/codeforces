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
const long long int N=3e5+30;
ll a[N],b[N];
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie();
   // ll T;
   // cin >> T;
   // while (T--){
        ll n;
        cin >> n;
        ll a[n],ans[n];
        rep (i,0,n) cin >> a[i];
        sort(a,a+n);
        ll p1 = 0,p2=n-1;
        cout << n/2+n%2-1 << endl;
        rep (i,0,n){
            if (i%2){
                ans[i] = a[p1];
                p1++;
            }
            else{
                ans[i] = a[p2];
                p2--;
            }
            cout << ans[i] << ' ';
        }
   // }
    return 0;
}
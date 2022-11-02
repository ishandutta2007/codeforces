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
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie();
   // ll T;
   // cin >> T;
   // while (T--){
        int n;
        cin >> n;
        long int a[n],ans[n];
        rep (i,0,n) cin >> a[i];
        sort(a,a+n);
        long int p1 = 0,p2=n-1,cnt=0;
        rep (i,0,n){
            if (i%2==0){
                ans[i] = a[p2];
                p2--;
            }
        }
        p1 = 1;
        ((n-1)%2)? p2 = n-1  :p2 = n-2;
        if (n == 1){
            cout <<0<<endl;
            cout << a[0];
            return 0;
        }
        if (n == 2){
            cout << 0<<endl;
            cout << a[0] << ' '<< a[1];
            return 0;
        }
        rep(i,0,n/2){
            if (a[n/2-1-i] < ans[p1-1] && a[n/2-1-i] < ans[p1+1]){
                ans[p1] = a[n/2-1-i];
                p1+=2;
            }
            else{
                ans[p2] = a[n/2-1-i];
                p2-=2;
            }
            
        }
        rep (i,1,n-1){
            if (ans[i] < ans[i+1] && ans[i] < ans[i-1]) cnt++;
        }
        cout << cnt << endl;
        rep (i,0,n) cout << ans[i] << ' ';
   // }
    return 0;
}
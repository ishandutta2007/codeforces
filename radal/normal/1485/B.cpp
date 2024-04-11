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
int a[N];
int main(){
    int T = 1;
   // cin >> T;
    while (T--){
        int n,q,k;
        cin >> n >> q >> k;
        rep(i,1,n+1) cin >> a[i];
        a[n+1] = k+1;
        rep(i,0,q){
            int l,r;
            cin >> l >> r;
            if (n == 1){
                cout << k-1 << endl;
                continue;
            }
          /*  if (l == r){
                if (l != 1 && l != n){
                    cout << a[l+1]-a[l-1]-2 << endl;
                    continue;
                }
                if (l == 1){
                    cout << a[2]-2 << endl;
                    continue;
                }
                cout << k-a[n-1]-1 << endl;
                continue;
            }*/
            cout << a[n+1]+a[r]-a[l]-2*(r-l+1) << endl;

        }
    }
    return 0;
}
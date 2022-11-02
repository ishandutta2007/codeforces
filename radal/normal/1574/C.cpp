#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 2e5+20,mod = 1e9+7;
ll a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
   // cin >> T;
    while (T--){
        int n;
        ll sm = 0;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
            sm += a[i];
        }
        sort(a,a+n);
        int m;
        cin >> m;
        rep(i,0,m){
            ll x,y;
            cin >> x >> y;
            /*if (x+y >= sm){
                if (a[0] <= x){
                    cout << x+y-sm << endl;
                    continue;
                }
                cout << y-sm+a[0] << endl;
                continue;
            }*/
            if (x >= a[n-1]){
                cout << x-a[n-1]+max(y-y,y-sm+a[n-1]) << endl;
                continue;
            }
            int ind = lower_bound(a,a+n,x)-a;
            ll ans = max(y-y,y-sm+a[ind]);
            if (ind)
                ans = min(ans,x-a[ind-1]+max(y-y,y-sm+a[ind-1]));
            cout << ans << endl;
        }
    }
}
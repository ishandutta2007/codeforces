#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,mi = 2e9,ind;
        vector<pair<pll,pll> > ans;
        cin >> n;
        rep(i,1,n+1){
            cin >> a[i];
            if (a[i] < mi){
                mi = a[i];
                ind = i;
            }
        }
        rep(i,1,ind) ans.pb({{ind,i},{a[ind],a[ind]+ind-i}});
        rep(i,ind+1,n+1) ans.pb({{ind,i},{a[ind],a[ind]+i-ind}});
        cout << n-1 << endl;
        rep(i,0,n-1) cout << ans[i].X.X << ' ' << ans[i].X.Y << ' ' << ans[i].Y.X << ' ' << ans[i].Y.Y << endl;

    }
    return 0;
}
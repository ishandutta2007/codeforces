#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=2e6+20,mod = 1e6+3,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
ll poww(ll n,int k){
    if (k == 1) return n;
    ll r = poww(n,k/2);
    ll ans;
    if (k%2 == 0) ans = (r*r)%mod;
    else ans = (n*r*r)%mod;
    return ans;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        vector<int> ve;
        cin >> n >>k;
        rep(i,k+1,n+1) ve.pb(i);
        repr(i,k-1,k/2+1) ve.pb(i);
        if (k%2 == 0) ve.pb(k/2);
        cout << ve.size() << endl;
        for (int u : ve) cout << u <<  ' ';
        cout<<endl;
        
    }
    return 0;
}
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
typedef unsigned long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e6+10,mod = 998244353,inf=4e18,maxm = 1000;
const long double eps = 0.0001;
int cnt[N];
vector<int> ve[N];
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    long long ans = poww(a,k/2);
    ans *= ans;
    ans %= mod;
    if (k%2){
        ans*=a;
        ans %= mod;
    }
    return ans;
}
int main(){
    ios :: sync_with_stdio(0);
    ll n;
    cin >> n;
    rep(i,0,n){
        int k;
        cin >> k;
        rep(j,0,k){
            int x;
            cin >> x;
            cnt[x]++;
            ve[i].pb(x);
        }
    }
    ll ans = 0;
    rep(i,0,n){
        ll k = ve[i].size();
        rep(j,0,k){
            ll a = (n*n*k)%mod;
            ans += cnt[ve[i][j]]*poww(a,mod-2);
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}
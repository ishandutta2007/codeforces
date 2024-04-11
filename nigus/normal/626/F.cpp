#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 998244353;

int DP[201][201][1001] = {0};
bool DPC[201][201][1001] = {0};

vl A;

int mod(ll i){
    if(i >= big)return i%big;
    return i;
}

int dp(ll i, ll nc, ll sumk){
    if(sumk > k || nc < 0)return 0;
    if(i == n){
        return (nc == 0);
    }
    if(DPC[i][nc][sumk])return DP[i][nc][sumk];
    int ans = 0;
    int dif = 0;
    if(i>0)dif = A[i]-A[i-1];

    // start new
    ans += dp(i+1,nc+1,sumk+dif*nc);
    ans = mod(ans);
    ans += dp(i+1,nc,sumk+dif*nc);
    ans = mod(ans);

    // same
    ans += mod(ll(nc)*ll(dp(i+1,nc,sumk+dif*nc)));
    ans = mod(ans);
    ans += mod(ll(nc)*ll(dp(i+1,nc-1,sumk+dif*nc)));
    ans = mod(ans);

    DPC[i][nc][sumk] = 1;
    DP[i][nc][sumk] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n >> k;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));
    int ans = dp(0,0,0);
    cout << ans << "\n";
    return 0;
}
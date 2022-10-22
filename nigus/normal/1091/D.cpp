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

ll n,m,T,k;
const ll big = 1000000007;
const ll big2 = 998244353;

ll NK[1000001] = {0};

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n;

    NK[1] = n;
    for(int c1 = 2; c1 <= n; c1++){
        NK[c1] = NK[c1-1]*(n-c1+1);
        NK[c1] %= big2;
    }

    ll ans = 0;
    ans = NK[n];
    for(int c1 = 1; c1 <= n-1; c1++){
        ans += 4*big2+NK[n]-NK[c1];
        ans %= big2;
    }

    cout << ans << "\n";

    return 0;
}
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

set<ll> S;

void solve(ll d){
    ll ans = n/d;
    ans += ( (n-d)*((n-d)/d + 1)  )/2;
    S.insert(ans);
    return;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n;

    for(int c1 = 1; c1*c1 <= n; c1++){
        if(n%c1 == 0){
            a = c1;
            b = n/c1;
            solve(a);
            solve(b);
        }
    }

    for(auto i : S){
        cout << i << " ";
    }

    return 0;
}
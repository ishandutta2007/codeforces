#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> a >> b;

    ll ans = 0;

    for(ll c1 = 1; c1 < a+b+2; c1++){
        c = a/c1 + b/c1;
        if(c >= n && !(a/c1 == 0 || b/c1 == 0))ans = c1;
    }

    cout << ans << "\n";

    return 0;
}
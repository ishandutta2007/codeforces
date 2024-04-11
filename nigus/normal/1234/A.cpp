#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 300001;

int main() {
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);

    ll a,b,c;

    cin >> q;
    rep(c1,0,q){
        cin >> n;
        b = 0;
        rep(c2,0,n){
            cin >> a;
            b += a;
        }
        cout << (b+n-1)/n << "\n";
    }


    return 0;
}
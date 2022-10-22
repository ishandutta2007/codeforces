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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

bool mark[1000000] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    ll x;
    cin >> n >> x;

    ll ans = (1 << (n)) - 1;
    if(x < (1 << n)){
        ans = (1 << (n-1)) - 1 ;
    }

    cout << ans << "\n";
    mark[0] = 1;
    ll prev = 0;
    for(int c1 = 1; c1 < (1 << n); c1++){
        if(!mark[c1^x]){
            mark[c1] = 1;
            cout << (c1 ^ prev) << " ";
            prev = c1;
        }
    }

    return 0;
}
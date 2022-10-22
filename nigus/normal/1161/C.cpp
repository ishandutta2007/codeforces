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

ll F[51] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        F[a]++;
    }

    for(int c1 = 0; c1 < 51; c1++){
        if(F[c1] > 0){
            if(F[c1] > n/2){
                cout << "Bob\n";
                return 0;
            }
            else{
                cout << "Alice\n";
                return 0;
            }
        }
    }

    return 0;
}
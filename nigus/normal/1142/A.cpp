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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

ll A,B;

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

bool start(ll x, ll L){
    ll des = (x+L)%k;
    ll d = min(des, k-des);
    if(d == B && min(x, k-x) == A)return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> k;
    cin >> A >> B;

    ll ans1 = big*big;
    ll ans2 = 0;

    ll C[2] = {A,(k-A)%k};

    for(ll L = 0; L <= n; L++){
        for(ll c1 = 0; c1 < 2; c1++){
            for(ll c2 = 0; c2 < 2; c2++){

                ll L2 = L*k - C[c1] + B;
                if(c2 == 1){
                    L2 = (L+1)*k - C[c1] - B;
                }

                if(L2 <= 0 || L2 > n*k)continue;

             //   cerr << L2 << "\n";

                if(start(C[c1],L2)){

                    ll temp = (n*k)/gcd(n*k,L2);
                    ans1 = min(ans1, temp);
                    ans2 = max(ans2, temp);
                 //   cerr << C[c1] << " " << L2 << " " << temp << "\n";
                }
            }
        }
    }

    cout << ans1 << " " << ans2 << "\n";

    return 0;
}
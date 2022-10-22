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
    return DD(eng)%r;
}

const ll big = 1000000007;

ll n,m,T,k,q;
const int MAXN = 5000;

unordered_map<ll,ll> M0;
unordered_map<ll,ll> M1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    M0[0] = 1;
    cin >> n;
    ll ans = 0;
    ll xo = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        xo ^= a;
        if((c1+1)%2 == 0){
            if(M0.find(xo) != M0.end()){
                ans += M0[xo];
                M0[xo]++;
            }
            else{
                M0[xo] = 1;
            }
        }
        else{
            if(M1.find(xo) != M1.end()){
                ans += M1[xo];
                M1[xo]++;
            }
            else{
                M1[xo] = 1;
            }
        }
    }

cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 500;

ll DP[101][101][101] = {0};
bool DPC[101][101][101] = {0};

ll dp(ll a, ll b, ll c){
    if(DPC[a][b][c])return DP[a][b][c];
    ll ans = 0;
    if(a >= 1 && b >= 2)ans = 3 + dp(a-1,b-2,c);
    if(b >= 1 && c >= 2)ans = max(ans, 3 + dp(a,b-1,c-2));
    DPC[a][b][c] = 1;
    DP[a][b][c] = ans;
    return ans;
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;


    cin >> T;

    rep(c1,0,T){
        cin >> a >> b >> c;
        cout << dp(a,b,c) << "\n";
    }



    return 0;
}
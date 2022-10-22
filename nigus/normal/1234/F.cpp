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

bool is[1 << 20];
int DP[1 << 20][20] = {0};
bool DPC[1 << 20][20] = {0};

int dp(int mask, int i){
    if(i == 20){
        return (is[((1 << 20)-1) ^ mask] * (20 - __builtin_popcount(mask)));
    }
    if(DPC[mask][i])return DP[mask][i];
    int ans = dp(mask,i+1);
    if(((1 << i)&mask) == 0){
        ans = max(ans,  dp((mask + (1 << i)), i+1));
    }
    DPC[mask][i] = 1;
    DP[mask][i] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;
    string s;
    cin >> s;
    n = s.length();
    is[0] = 1;
    rep(c1,0,n){
        int mask = 0;
        for(int c2 = c1; c2 >= 0; c2--){
            a = s[c2]-'a';
            if((mask&(1 << a)) != 0)break;
            mask += (1 << a);
            is[mask] = 1;
        }
    }

    int ans = 0;
    rep(c1,0,(1 << 20)){
        if(is[c1]){
          //  cerr << c1 << " " << dp(c1,0) << "\n";
            ans = max(ans, __builtin_popcount(c1) + dp(c1,0));
        }
    }
    cout << ans << "\n";

    return 0;
}
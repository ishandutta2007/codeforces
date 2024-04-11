
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

const int MAXN = 1000001;

ll DP[2001][4001] = {0};
bool DPC[2001][4001] = {0};

vl A;

ll dp(ll i, ll diff){
    if(i == n)return (diff == 2000);
    if(diff >= 4001)return 0;
    if(DPC[i][diff])return DP[i][diff];
    ll ans = 0;
    ll nex = (i+1)%n;
    if(A[i] == A[nex]){
        ans = (k*dp(i+1,diff))%mod;
    }
    else{
        ans = (dp(i+1,diff+1) + dp(i+1,diff-1) + (k-2)*dp(i+1,diff))%mod;
    }
    DPC[i][diff] = 1;
    DP[i][diff] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;
    rep(c1,0,n){
        cin >> a;
       // a = random2()%k + 1;
        A.push_back(a);
    }

    ll ans = 0;
    rep(c1,2001,4001){
        ans += dp(0,c1);
        ans %= mod;
    }

    cout << ans << "\n";

    return 0;
}
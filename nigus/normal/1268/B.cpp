
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

const int MAXN = 300001;

ll DP[MAXN][3] = {0};
bool DPC[MAXN][3] = {0};

vl A;

ll dp(ll i, ll prev){
    if(i == n){
        if(prev != 0)return -big*big;
        return 0;
    }
    if(DPC[i][prev])return DP[i][prev];
    ll ans = 0;

    ans = max(ans, (A[i]-prev)/2 + dp(i+1, 0));

    if(prev != 1 && i != n-1){
        ans = max(ans, 1 + (A[i]-max(1ll,prev))/2 + dp(i+1, 1));
    }
    if(prev != 2 && A[i] != 1 && i != n-1 && A[i+1] != 1){
        ans = max(ans, 1 + (A[i]-2)/2 + dp(i+1, 2));
    }

   // cerr << i << " " << prev << "   ans=" << ans << "\n";

    DP[i][prev] = ans;
    DPC[i][prev] = 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    //n = 29999-1;
    ll black = 0;
    ll white = 0;
    rep(c1,0,n){
        cin >> a;
        black += a/2;
        white += a/2;
        if(a%2 == 1 && c1%2 == 0)black++;
        if(a%2 == 1 && c1%2 == 1)white++;
        //a = n-c1;
        A.push_back(a);
    }

    //ll ans = dp(0,0);
   // cout << ans << "\n";
   cout << min(black, white) << "\n";
  //  cerr << "ans? " << min(black, white) << "\n";

    return 0;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

string s;

ll F[26] = {0};
ll FF[26][26] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> s;
    n = s.length();
    for(int c1 = n-1; c1 >= 0; c1--){
        c = s[c1]-'a';
        for(int c2 = 0; c2 < 26; c2++){
            FF[c][c2] += F[c2];
        }
        F[c]++;
    }

    ll ans = 0;
    rep(c1,0,26){
        ans = max(ans, F[c1]);
        rep(c2,0,26){
            ans = max(ans, FF[c1][c2]);
        }
    }

    cout << ans << "\n";

    return 0;
}
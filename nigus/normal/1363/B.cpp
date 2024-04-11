#pragma GCC optimize("O3")   //
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
typedef unsigned long long ull;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 5001;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(_,0,T){
        string s;
        cin >> s;
        ll N[2] = {0};
        trav(ch,s){
            N[ch-'0']++;
        }
        n = sz(s);
        ll ans = min(N[0],N[1]);
        ll N2[2] = {0};
        trav(ch,s){
            N2[ch-'0']++;
            ans = min(ans, N[0]-N2[0]+N2[1]);
            ans = min(ans, N[1]-N2[1]+N2[0]);
        }
        cout << ans << "\n";
    }

    return 0;
}
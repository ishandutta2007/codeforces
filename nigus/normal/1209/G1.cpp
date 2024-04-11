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

const ll MAXN = 200001;

ll MA[MAXN] = {0};

vl A;

ll F[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> q;

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        MA[a] = c1;
    }
    ll ans = 0;
    ll sum = 0;
    ll tot = 0;
    ll ma = 0;
    rep(c1,0,n){

        if(F[A[c1]] == 0)sum++;
        F[A[c1]]++;
        ma = max(ma, F[A[c1]]);
        tot++;
        if(MA[A[c1]] == c1)sum--;

        if(sum == 0){
            ans += tot-ma;
            tot = 0;
            ma = 0;
        }
    }

    cout << ans << "\n";

    return 0;
}
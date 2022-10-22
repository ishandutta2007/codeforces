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

const int MAXN = 251;


ll powk[MAXN] = {0};
ll powk2[MAXN] = {0};

ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%big;
    return (((h*h)%big)*i)%big;
}

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    ll a = (FAC[i]*INV[j])%big;
    return (a*INV[i-j])%big;
}

ll DP[MAXN][MAXN] = {0};
bool DPC[MAXN][MAXN] = {0};

ll dp(ll i, ll oned){
    if(i == n)return (oned==n);
    if(DPC[i][oned])return DP[i][oned];
    ll ans = 0;
    for(ll ss = 0; ss <= n-oned; ss++){
        ll a = (bin(n-oned,ss)*powk2[n-oned-ss])%big;
        ll b = powk[oned];
        if(ss == 0)b += 2*big - powk2[oned];
        b %= big;
        ll c = (a*b)%big;
        c *= dp(i+1,oned+ss);
        c %= big;
        ans += c;
        ans %= big;
        //cerr << powk2[0] << " "<< powk2[3] << "\n";
       // cerr << i << " " << oned << "   -  " << bin(n-oned,ss) << " " << n-oned-ss << "\n";

    }
    DPC[i][oned] = 1;
    DP[i][oned] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    a = 1;
    rep(c1,0,251){
        FAC[c1] = a;
        INV[c1] = upp(a,big-2);
        //cerr << (FAC[c1]*INV[c1])%big << "\n";
        a*=ll(c1+1);
        a%=big;
    }

    cin >> n >> k;

    ll t = 1;
    ll t2 = 1;
    rep(c1,0,251){
        powk[c1] = t;
        powk2[c1] = t2;
        t *= k;
        t %= big;
        t2 *= (k-1);
        t2 %= big;
       // cerr << powk2[c1] << "\n";
    }




    ll ans = dp(0,0);
    cout << ans << "\n";

    return 0;
}
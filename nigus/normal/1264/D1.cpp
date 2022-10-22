
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

ll totm = 0;
ll totp = 0;
ll totq = 0;

string s;

ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%mod;
    return (((h*h)%mod)*i)%mod;
}

void setup(){
    ll t = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        t *= ll(c1)+1;
        t %= mod;
    }
    INV[MAXN-1] = upp(FAC[MAXN-1], mod-2);
    for(ll c1 = MAXN-2; c1 >= 0; c1--){
        INV[c1] = (INV[c1+1]*(c1+1))%mod;
    }
}

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    ll a = (FAC[i] * INV[i-j])%mod;
    return (a*INV[j])%mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    setup();

    cin >> s;
    n = s.length();
    rep(c1,0,n){
        if(s[c1] == '(')totp++;
        if(s[c1] == '?')totq++;
        if(s[c1] == ')')totm++;
    }

    ll lq = 0;
    ll lm = 0;
    ll lp = 0;

    ll ans = 0;

    rep(c1,0,n){
        if(s[c1] == '(')lp++;
        if(s[c1] == '?')lq++;
        if(s[c1] == ')')lm++;
        ll rq = totq-lq;
        ll rm = totm-lm;
        ll rp = totp-lp;
        ll i = c1+1;
        if(i < totm)continue;
        ll extra = i-totm;
        for(ll j = 0; j <= extra; j++){
            a = rm+j;
            b = (bin(rq,j) * bin(lq,extra-j))%mod;
            ans += (a*b)%mod;
            ans %= mod;
        }
    }

    cout << ans << "\n";

    return 0;
}
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

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 400001;

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0){
        return (h*h)%mod;
    }
    return (((h*h)%mod) * i)%mod;
}

/*
ll FAC[MAXN] = {0};
ll FINV[MAXN] = {0};
ll INV[MAXN] = {0};

void setup(){
    ll t = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        t *= c1+1;
        t %= mod;
    }
    FINV[MAXN-1] = upp(FAC[MAXN-1], mod-2);
    for(ll c1 = MAXN-2; c1 >= 0; c1--){
        FINV[c1] = (FINV[c1+1] * (c1+1))%mod;
        INV[c1+1] = (FAC[c1] * FINV[c1+1])%mod;
    }
}

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    ll tal = FAC[i];
    ll nam = (INV[j] * INV[i-j])%mod;
    return (tal*nam)%mod;
}
*/
int P1[5001][5001] = {0};
int P2[5001][5001] = {0};
bool DPC[5001][5001] = {0};

ll WMI, WMA;
vl A,W;

pll getp(ll i, ll j){
    if(i+j == m)return {(WMI-i)%mod,(WMA+j)%mod};
    if(i < 0 || j < 0)return {0,0};
    if(i > WMI)return {0,0};
    if(DPC[i][j])return {P1[i][j], P2[i][j]};
    ll wmi = WMI-i;
    ll wma = WMA+j;
    ll tot = (wmi+wma)%mod;
    ll toti = upp(tot,mod-2);
    pll p1 = getp(i+1,j);
    pll p2 = getp(i,j+1);
    ll ans1 = ((wmi*toti)%mod) * p1.first + ((wma*toti)%mod) * p2.first;
    ll ans2 = ((wmi*toti)%mod) * p1.second + ((wma*toti)%mod) * p2.second;
    ans1 %= mod;
    ans2 %= mod;
    DPC[i][j] = 1;
    P1[i][j] = ans1;
    P2[i][j] = ans2;
    return {ans1, ans2};
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
   // setup();
    cin >> n >> m;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }

    rep(c1,0,n){
        cin >> a;
        if(A[c1] == 0){
            WMI+=a;
        }
        else{
            WMA+=a;
        }
        W.push_back(a);
    }

    rep(c1,0,n){
        ll ans1 = getp(0,0).first;
        ll ans2 = getp(0,0).second;
      //  cerr << ans1 << " " << ans2 << "\n";
        ll rat = W[c1];
        if(A[c1] == 0){
            rat *= upp(WMI, mod-2);
            rat %= mod;
            cout << (rat*ans1)%mod << "\n";
        }
        else{
            rat *= upp(WMA, mod-2);
            rat %= mod;
            cout << (rat*ans2)%mod << "\n";
        }

    }

    return 0;
}
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
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return DD(eng)%r;
}

const ll big = 1000000007;

ll n,m,T,k,q;
const int MAXN = 1000000;


ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%big;
    return (((h*h)%big)*i)%big;
}

ll FAC[MAXN+1] = {0};
ll INV[MAXN+1] = {0};
ll DOWN[MAXN+1] = {0};

ll bin(ll i, ll j){
    if(i < j || j < 0 || i < 0)return 0;
    ll den = (FAC[i]*INV[j])%big;
    return (den*INV[i-j])%big;
}

void setup(){
    ll t = 1;
    ll t2 = 1;
    for(ll c1 = 0; c1 <= n-2; c1++){
        DOWN[c1] = t2;
        t2 *= n-2-c1;
        t2 %= big;
    }
    for(ll c1 = 0; c1 < MAXN+1; c1++){
        FAC[c1] = t;
        t *= c1+1;
        t %= big;
    }
    INV[MAXN] = upp(FAC[MAXN],big-2);
    for(ll c1 = MAXN-1; c1 >= 0; c1--){
        INV[c1] = (INV[c1+1]*(c1+1))%big;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m >> a >>  b;
   // n = 1000000;
   // m = 1000000;
  //  a = 0;
  //  b = 0;
    if(n == 2){
        cout << "1\n";
        return 0;
    }
    setup();


    ll ans = 0;
    for(ll extra = 0; extra <= n-2; extra++){
        if(m < extra+1)break;
        ll temp = bin(m-1,extra);
        temp *= DOWN[extra];
        temp %= big;
        ll r = n-2-extra;
        temp *= upp(m,r);
        temp %= big;
       // cerr << temp << "  r: " << r << "   DOWN: " << DOWN[extra] << "\n";
        if(r != 0){
            temp *= (n-r);
            temp %= big;
            temp *= upp(n,r-1);
        }
        ans += temp;
        ans %= big;
      //  cerr << temp << "\n";
    }
    cout << ans << "\n";

    return 0;
}
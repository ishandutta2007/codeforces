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

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1000002;

ll i2 = (big+1)/2;
ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};
ll I2[MAXN] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2)%big;
    if(j%2 == 0)return (h*h)%big;
    return (((h*h)%big)*i)%big;
}

ll bin(ll i, ll j){
    if(i < 0 || j < 0 || i < j)return 0;
    ll p = (FAC[i]*INV[j])%big;
    return (p * INV[i-j])%big;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    ll t = 1;
    ll p = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        t *= ll(c1+1);
        t %= big;
        I2[c1] = p;
        p *= i2;
        p %= big;
    }

    INV[MAXN-1] = upp(FAC[MAXN-1], big-2);
    for(int c1 = MAXN-2; c1 >= 0; c1--){
        INV[c1] = (INV[c1+1] * ll(c1+1))%big;
    }

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m >> k;
        m=n-m;


        ll ans = 0;

        if(m == 0){
            ans = n;
        }
        else{
           // cerr << n << " " << m << "  h\n";
            rep(i,1,n){
                ll temp = bin(n-i-1, m-1) * I2[n-i];
                temp %= big;
                ans += temp * ll(i);
                ans %= big;
            }
        }
        ans *= k;
        ans %= big;
        cout << ans << "\n";
    }


    return 0;
}
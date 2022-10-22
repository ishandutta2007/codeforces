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

const ll MAXN = 1001;



ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

ll A[MAXN][MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        rep(c2,0,n){
            cin >> a;
            A[c1][c2] = a;
        }
    }

    ll a12 = (A[0][1] * A[0][2]) / (A[1][2]);

    ll rtt = ll(sqrt(a12));

    for(ll rt2 = rtt-100; rt2 < rtt+100; rt2++){
        if(rt2*rt2 == a12 && rt2 > 0){
            a = rt2;
            break;
        }

    }

    cout << a << " ";
    rep(c1,1,n){
        cout << A[0][c1]/a << " ";
    }cout <<"\n";



    return 0;
}
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

ll a,b,e;
ll ans;

ld diff(ll x){
    return abs((x*a + (x-1)*b)/ld(2*x-1) - ld(e));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

  //  ll a,b,c,d,e;

    cin >> T;
    rep(_,0,T){
        cin >> a >> b >> e;


        if(2*e <= a+b){
            cout << "2\n";
        }
        else{
            ll x = (b-e)/(a+b-2*e);
            ld ave = diff(x);
            ld ave2 = diff(x+1);
            if(ave2 + 0.00000000000001 < ave){
                cout << 2*x+1 << "\n";
            }
            else{
                cout << 2*x-1 << "\n";
            }
        }

    }

    return 0;
}
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

const int MAXN = 2000001;

vl get_v(ll i){
    if(i == n-1){
        return {n-1,n,1};
    }
    vl ANS;
    rep(c1,i+1,n+1){
        ANS.push_back(i);
        ANS.push_back(c1);
    }
    return ANS;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        ll l,r;
        cin >> n >> l >> r;
        ll moves = 0;
        rep(c1,1,n){
            ll tot = 2*n-2*ll(c1);
            if(c1 == n-1)tot = 3;
          //  if(c1 > n-10)cerr << moves << "  gfd\n";
            if(moves + tot < l || moves >= r){
                moves += tot;
            }
            else{
                vl v = get_v(c1);
               // cerr << "HEJ " << c1 << "\n";
                trav(j, v){
                    moves++;
                    if(moves >= l && moves <= r){
                        cout << j << " ";
                    }
                }
            }
        }
        cout << "\n";
    }

    return 0;
}
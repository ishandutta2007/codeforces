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

const int MAXN = 300001;

vector<vl> W(3, vl());
ll N[3] = {0};

ll smaller(ll i, ll x){
    ll l = 0;
    ll r = N[i];

    if(W[i][0] > x)return -1;

    while(l < r-1){
        ll mid = (l+r)/2;
        if(W[i][mid] <= x){
            l = mid;
        }
        else{
            r = mid;
        }

    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        W[0].clear();
        W[1].clear();
        W[2].clear();
        rep(c1,0,3){
            cin >> N[c1];
        }
        rep(c1,0,3){
            rep(c2,0,N[c1]){
                cin >> a;
                W[c1].push_back(a);
            }
            sort(all(W[c1]));
        }

        ll ans = 3*big*big;

        rep(c1,0,3){
            rep(c2,0,N[c1]){
                ll mid = W[c1][c2];
                rep(i,0,3){
                    rep(j,0,3){
                        if(i != c1 && j != c1 && i != j){
                            ll i1 = smaller(i, mid);
                            ll i2 = smaller(j, mid);
                            if(i2 == -1 || W[j][i2] < mid)i2++;
                            if(i1 == -1 || i2 == N[j])continue;
                            ll w1 = W[i][i1];
                            ll w2 = W[j][i2];
                            ans = min(ans, (w1 - mid)*(w1 - mid) + (w2 - mid)*(w2 - mid) + (w1 - w2)*(w1 - w2));
                        }
                    }
                }
            }
        }

        cout << ans << "\n";

    }

    return 0;
}
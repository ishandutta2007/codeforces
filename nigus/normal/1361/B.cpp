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

const int MAXN = 1000003;

vi K;

int CC[MAXN] = {0};
int cc = 0;
int F[MAXN] = {0};

ll p;

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%big;
    return (((h*h)%big)*i)%big;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(_,0,T){
        cin >> n >> p;
        K.clear();

        cc++;
        rep(c1,0,n){
            cin >> a;
            if(CC[a] != cc){
                CC[a] = cc;
                F[a] = 0;
                K.push_back(a);

            }
            F[a]++;
        }

        if(p == 1){
            cout << n%2 << "\n";
            continue;
        }

        sort(all(K));
        reverse(all(K));

        ll ans = 0;
        bool overflow = 0;

        ll prev = K[0];

        ll ove = 0;
        ll t = 1;
        while(t < big){
            t *= p;
            ove++;
        }

        bool zero = 0;

        trav(i, K){
            ll ex = upp(p, prev-i);
            ans *= ex;


            if(ans >= big || (prev-i >= ove && !zero)){
                overflow = 1;
            }

            prev=i;
            ans %= big;
            zero = 0;
            if(overflow || ans > F[i]){
                ans -= F[i];
                if(ans < 0)ans += big;
            }
            else{
                ans = (F[i]+ans)%2;
                if(ans == 0)zero = 1;
            }
        }
        ans *= upp(p, K[sz(K)-1]);
        ans %= big;
        cout << ans << "\n";

    }

    return 0;
}
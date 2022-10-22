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

const int MAXN = 100001;

ll F[MAXN] = {0};
vl A;

vl X;

int mark[MAXN] = {0};
int cc = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;
    rep(c1,0,n){
        cin >> a;
        F[a]++;
        A.push_back(a);
    }

    if(k >= 50){
        cout << (F[1]*F[1] - F[1])/2 << "\n";
        return 0;
    }

    ll ans = 0;

    ll hej = 0;

    for(ll x = 1; x <= 100000; x++){
        ll y = x;
        rep(c1,0,k-1){
            y *= x;
            if(y > 1e10)break;
        }
        hej++;
        if(y > 1e10)break;

        X.push_back(y);

        if(k == 2){
            vl factors;
            for(ll f = 1; f*f <= x; f++){
                if(x%f == 0){
                    factors.push_back(f);
                    if(f*f != x)factors.push_back(x/f);
                   // hej++;
                }
            }

            cc++;



            rep(c1,0,sz(factors)){
                rep(c2,0,sz(factors)){
                   // hej++;
                    ll f = factors[c1] * factors[c2];
                    if(f >= (ll)MAXN)continue;
                    if(mark[f] == cc)continue;
                    mark[f] = cc;

                    ll f2 = y/f;
                    if(f2 >= (ll)MAXN)continue;
                    mark[f2] = cc;


                    //cerr << f << " " << f2 << "\n";


                    if(f != f2){
                        ans += F[f]*F[f2];
                    }
                    else{
                        ans += (F[f]*F[f] - F[f])/2;
                    }

                }
            }
        }
        else{

            vl factors; // ax(1ll, y/100000)
            for(ll f = 1; f*f <= y; f++){
                if(y%f == 0){
                    ll f2 = y/f;
                    if(f <= 1e5 && f2 <= 1e5){
                        if(f != f2){
                            ans += F[f]*F[f2];
                        }
                        else{
                            ans += (F[f]*F[f] - F[f])/2;
                        }
                    }
                }
            }

        }

    }
    //cerr << hej << "\n";
    cout << ans << "\n";

    return 0;
}
#pragma GCC optimize("O3")
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

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 5002;

ll TOT[MAXN] = {0};
vi grass;
int CCS[MAXN][MAXN] = {0};

int F[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,n){
        cin >> a;
        a--;
       // a = rand()%1000;
        grass.push_back(a);
        TOT[a]++;
    }
    rep(c1,0,m){
        cin >> a >> b;
        a--;
       // a = rand()%1000;
       // b = rand()%30;
        CCS[a][b]++;
    }
    rep(c1,0,n){
        rep(c2,1,n+1){
            CCS[c1][c2] += CCS[c1][c2-1];
        }
    }

    int cows = 0;
    ll ways = 1;

    // one side
    rep(c1,0,n){
        if(CCS[c1][TOT[c1]] != 0){
            cows++;
            ways *= ll(CCS[c1][TOT[c1]]);
            ways %= big;
        }
    }
    /*
    if(cows > 0){
        ways *= 2;
        ways %= big;
    }
    */

    // fix left

    rep(c1,0,n){
        ll ci = grass[c1];
        F[ci]++;
        ll cf = F[ci];
        if(CCS[ci][cf]-CCS[ci][cf-1] > 0){
            ll other_side = 0;
            ll ways2 = 1;
            ll cows2 = 1;
            rep(c2,0,n){
                if(CCS[c2][TOT[c2]] > 0){
                    ll L = F[c2];
                    ll R = TOT[c2] - F[c2];
                    if(c2 == ci){
                        ll cw = CCS[c2][R];
                        if(R >= cf)cw--;
                        if(cw != 0){
                            other_side = 1;
                            ways2 *= cw;
                            ways2 %= big;
                            cows2++;
                        }
                    }
                    else{
                        L = ll(CCS[c2][L]);
                        R = ll(CCS[c2][R]);
                        if(R*L - min(R,L) > 0){
                            other_side = 1;
                            ll temp = R*L - min(R,L);
                            temp %= big;
                            ways2 *= temp;
                            ways2 %= big;
                            cows2 += 2;
                        }
                        else{
                            if(R == 1 && L == 1){
                                ways2 *= 2;
                                ways2 %= big;
                                cows2++;
                            }
                            else{
                                if(max(R,L) > 0){
                                    ways2 *= max(R,L);
                                    cows2++;
                                    ways2 %= big;
                                    if(R > 0)other_side = 1;

                                }
                            }
                        }

                    }

                }
            }

           // cerr << c1+1 << ": " << cows2 << " " << ways2 << " gfd\n";

           // if(other_side == 0)break;

            if(cows2 < cows)continue;

            if(cows2 > cows){
                cows = cows2;
                ways = 0;
            }
            ways += ways2;
            ways %= big;

        }
    }

    cout << cows << " " << ways << "\n";

    return 0;
}
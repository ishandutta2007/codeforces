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

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vector<vi> L;

int W[81][81] = {0};

int DP[81][11] = {0};
int curr = 0;

int mark[81] = {0};

vi non;

int I[81][81][81] = {0};
int SUM[81][81][81] = {0};

int v[11] = {0};

int solve(){
    curr++;
    v[k/2] = 0;
    rep(i,0,k/2){
        mark[v[i]] = curr;
    }

    int ans = 0;
    rep(c1,0,k/2){
        int r = 0;
        int i = v[c1];
        int j = v[c1+1];
        //cerr << i << " " << j << "\n";
        while(mark[I[i][j][r]] == curr){
            r++;
        }
        ans += SUM[i][j][I[i][j][r]];
    }
    return ans;
}

ll s1,s2;

bool comp(ll i, ll j){
    return SUM[s1][s2][i] < SUM[s1][s2][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;
  //n = 80;
  //k = 10;

    rep(c1,0,n){
        rep(c2,0,n){
            cin >> W[c1][c2];
            //W[c1][c2] = rand();

        }
        W[c1][c1] = 1e8;
    }

    rep(c1,0,n){
        rep(c2,0,n){
            vi ind;
            rep(c3,0,n){
                ind.push_back(c3);
                SUM[c1][c2][c3] = W[c1][c3] + W[c3][c2];
            }
            s1 = c1;
            s2 = c2;
            sort(all(ind), comp);
            rep(c3,0,sz(ind)){
                I[c1][c2][c3] = ind[c3];
            }
        }
    }

    rep(c1,1,n){
        DP[c1][k] = big*2;
    }

    int ans = 2*big;

    v[0] = 0;
    v[k/2] = 0;


    if(k == 2){
        ans = min(ans, solve());
    }

    rep(c1,0,n){
        v[1] = c1;
        if(k == 4){
            ans = min(ans, solve());
        }
        rep(c2,0,n){
            v[2] = c2;
            if(k == 6){
                ans = min(ans, solve());
            }
            rep(c3,0,n){
                v[3] = c3;
                if(k == 8){
                    ans = min(ans, solve());
                }
                rep(c4,0,n){
                    v[4] = c4;
                    if(k == 10){
                        ans = min(ans, solve());
                    }
                }
            }
        }
    }


    cout << ans << "\n";

    return 0;
}
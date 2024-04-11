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

const int MAXN = 3001;

ll TWO[MAXN] = {0};

ll DP[MAXN][MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    ll t2 = 1;
    rep(c1,0,MAXN){
        TWO[c1] = t2;
        t2 *= 2;
        t2 %= mod;
    }

    string s;
    string t;
    cin >> s;
   cin >> t;

    /*
    s = "";
    t = "";
    rep(c1,0,50){
        s += 'a';
    }
    rep(c1,0,50){
        t += 'a';
    }
*/
    n = s.length();
    m = t.length();
    //reverse(all(s));

    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                if(i < m){
                    if(t[i] == s[0]){
                        DP[i][j] = 2;
                    }
                    else{
                        DP[i][j] = 0;
                    }
                }
                else{
                    DP[i][j] = 2;
                }
                continue;
            }
            k = j-i;
            DP[i][j] = 0;

            if(i < m){
                if(s[k] == t[i]){
                    DP[i][j] += DP[i+1][j];
                }
            }
            else{
                DP[i][j] += DP[i+1][j];
            }
            if
                (j < m){
                if(s[k] == t[j]){
                    DP[i][j] += DP[i][j-1];
                }
            }
            else{
                DP[i][j] += DP[i][j-1];
            }

            DP[i][j] %= mod;
        }
    }
    /*
    rep(c1,0,n){
        rep(c2,0,n){
            cerr << DP[c1][c2] << " ";
        }cerr << "\n";
    }
*/
    ll ans = 0;
    rep(c1,m-1,n){
        ans += DP[0][c1];
        ans %= mod;
    }

    cout << ans << "\n";

    return 0;
}
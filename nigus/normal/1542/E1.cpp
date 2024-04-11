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

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 501;

ll MOD;

int DP[MAXN][(MAXN*MAXN)/2] = {0};

int PREF[MAXN][(MAXN*MAXN)/2] = {0};

ll solve(int n2, int k)
{
    // Taken from https://codeforces.com/blog/entry/80480
    //if(n == 0)return (k == 0);
    int total = n2 * (n2 - 1) / 2;
    if (k < 0 || k > total) return 0;
    k = min(k, total - k);
    if (DP[n2][k] != -1) return DP[n2][k];
    if (k == 0) return DP[n2][0] = 1;
    if (n2 == 0) return DP[0][k] = 0;
    return DP[n2][k] = ((solve(n2, k - 1) + solve(n2 - 1, k))%MOD - solve(n2 - 1, k - n2) + MOD) % MOD;
}

vector<vi> perms;
vi curr;
void gen(int i){
    if(i == 1){
        curr.push_back(0);
        perms.push_back(curr);
        curr.pop_back();
        return;
    }
    rep(c1,0,i){
        curr.push_back(c1);
        gen(i-1);
        curr.pop_back();
    }
}

ll brute(){
    gen(n);
    ll ans = 0;
    trav(y, perms){
        trav(z, perms){
            bool good = 0;
            int suma = 0;
            int sumb = 0;
            rep(c1,0,n){
                if(y[c1] < z[c1]){
                    good = 1;
                    break;
                }
                if(y[c1] > z[c1]){
                    good = 0;
                    break;
                }
            }
            rep(c1,0,n){
                suma += y[c1];
                sumb += z[c1];
            }
            if(suma <= sumb)good = 0;
            ans += good;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> n >> MOD;

    //MOD = 1000000000;

    rep(c1,0,MAXN){
        rep(c2,0,MAXN*MAXN/2){
            DP[c1][c2] = -1;
        }
    }
    // 20 100000
    ll temp = 1;
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        for(int inv = 1; inv < 3+(i*i)/2; inv++){
            PREF[i][inv] = PREF[i][inv-1] + solve(i, inv-1);
            if(PREF[i][inv] >= MOD)PREF[i][inv] -= MOD;
        }
        ll tmp = 0;
        for(int diff = 1; diff <= i; diff++){
            ll extra = i-diff+1;
            for(int inv = 0; inv < 3+(i*i)/2; inv++){
                int upper = inv - diff;
                upper = max(upper, 0);
                tmp += extra * ((solve(i, inv) * ll(PREF[i][upper]))%MOD);
                tmp %= MOD;
            }
        }

        tmp *= temp;

        ans += tmp;
        ans %= MOD;


        temp *= ll(i+1);
        temp %= MOD;
    }

    cout << ans << "\n";
   // cerr << brute() << "\n";


    return 0;
}
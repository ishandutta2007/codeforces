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

const int MAXN = 200001;

string s,t,s2,t2;

ll DP[2001][2001] = {0};

ll CSA[2002][26] = {0};
ll CSB[2002][26] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(_,0,T){
        cin >> n;
        cin >> s >> t;
        s2 = s;
        t2 = t;
        sort(all(s2));
        sort(all(t2));
        if(t2 != s2){
            cout << "-1\n";
        }
        else{

            reverse(all(s));
            reverse(all(t));

            string alfa = "abcdefghijklmnopqrstuvwxyz";

            rep(c1,0,26){
                CSA[0][c1] = 0;
                CSB[0][c1] = 0;
                rep(c2,0,n){
                    CSA[c2+1][c1] = CSA[c2][c1] + (s[c2] == alfa[c1]);
                    CSB[c2+1][c1] = CSB[c2][c1] + (t[c2] == alfa[c1]);
                }
            }

            for(int c1 = n; c1 >= 0; c1--){
                for(int c2 = n; c2 >= 0; c2--){
                    if(max(c1,c2) == n){
                        DP[c1][c2] = 0;
                    }
                    else{
                        DP[c1][c2] = 0;
                        if(s[c1] == t[c2]){
                            DP[c1][c2] = max(DP[c1][c2], 1 + DP[c1+1][c2+1]);
                        }
                        DP[c1][c2] = max(DP[c1][c2], DP[c1+1][c2]);
                        if(CSB[c2][t[c2]-'a'] < CSA[c1][t[c2]-'a'])DP[c1][c2] = max(DP[c1][c2], DP[c1][c2+1]);
                    }
                }
            }
            cout << n-DP[0][0] << "\n";
        }
    }


    return 0;
}
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

const int MAXN = 300001;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        string s;
        cin >> n >> k;
        cin >> s;
        int F[26] = {0};
        trav(c,s){
            F[c-'a']++;
        }
        string ans = "";
        int curr = 0;
        string alfa = "abcdefghijklmnopqrstuvwxyz";

        int diff = 0;
        int L = 0;
        vi LL;
        rep(c1,0,26){
            if(F[c1] != 0){diff++;L = c1;LL.push_back(c1);}
        }

        if(diff == 1){
                rep(c1,0,(n+k-1)/k){
                    cout << alfa[L];
                }cout << "\n";
            continue;
        }

        if(diff == 2 && F[LL[0]] == k){
            cout << alfa[LL[0]];
            rep(c1,0,(F[LL[1]]+k-1)/k){
                cout << alfa[LL[1]];
            }
            cout << "\n";
            continue;
        }

        if(F[LL[0]] >= k){
            F[LL[0]] -= k;
            ans += alfa[LL[0]];
            rep(c1,0,26){
                rep(c2,0,F[c1]){
                    ans += alfa[c1];
                }
            }
            cout << ans << "\n";
            continue;
        }

        rep(c1,0,26){
            curr += F[c1];
            if(curr >= k){
                cout << alfa[c1] << "\n";
                break;
            }
        }

    }

    return 0;
}
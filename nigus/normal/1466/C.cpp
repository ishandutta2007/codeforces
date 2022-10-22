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

const int MAXN = 100001;

int DP[2][27][27] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;

    rep(c4,0,T){
        string s;
        cin >> s;
        n = sz(s);
        for(int i = 0; i < n; i++){
            for(int c1 = 0; c1 < 27; c1++){
                for(int c2 = 0; c2 < 27; c2++){
                    bool must_change = 0;
                    int ch = s[i]-'a';
                    if(ch == c1 || ch == c2)must_change = 1;
                    if(i == 0){
                        DP[i%2][c1][c2] = must_change;
                    }
                    else{
                        DP[i%2][c1][c2] = DP[(i+1)%2][26][c1] + 1;
                        if(!must_change){
                            DP[i%2][c1][c2] = min(DP[i%2][c1][c2], DP[(i+1)%2][ch][c1]);
                        }
                    }
                }
            }
        }
        int ans = DP[(n+1)%2][26][26];
        cout << ans << "\n";
    }

    return 0;
}
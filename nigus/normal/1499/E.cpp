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

const int MAXN = 1007;

string s,t;

int DP[MAXN][MAXN][27] = {0};
bool DPC[MAXN][MAXN][27] = {0};

int dp(int i, int j, int last){
    if(i == sz(s) && j == sz(t))return 1;
    if(DPC[i][j][last])return DP[i][j][last];
    int ans = 1;
    if(i < sz(s) && s[i]-'a' != last)ans += dp(i+1,j,s[i]-'a');
    if(j < sz(t) && t[j]-'a' != last)ans += dp(i,j+1,t[j]-'a');
    if(ans >= mod)ans -= mod;
    DP[i][j][last] = ans;
    DPC[i][j][last] = 1;
    return ans;
}

int rem(string ss){
    int runs = 0;
    int prev = -1;
    int temp = 0;
    rep(c1,0,sz(ss)){
        if(ss[c1]-'a' == prev)runs = 0;
        runs++;
        temp += runs;
        prev = ss[c1]-'a';
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> s >> t;
    int ans = 0;
    rep(c1,0,sz(s)){
        rep(c2,0,sz(t)){
            ans += dp(c1,c2,26);
            if(ans >= mod)ans -= mod;
        }
    }
    int gone = (rem(s)*sz(t)+rem(t)*sz(s)+sz(s)*sz(t))%mod;
    cout << (ans+mod-gone)%mod << "\n";

   // cerr << rem(s) << " " << rem(t) << " " << rem(s)*sz(t)+rem(t)*sz(s)+sz(s)*sz(t) << "\n";

    return 0;
}
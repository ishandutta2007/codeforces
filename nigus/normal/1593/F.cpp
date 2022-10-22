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

const ll MAXN = 41;

ll B,R;
string s;

bool next_state[MAXN][MAXN][MAXN][MAXN] = {0};
int DP[MAXN][MAXN][MAXN][MAXN] = {0};
int CC[MAXN][MAXN][MAXN][MAXN] = {0};
int cc = 0;

int dp(int b, int r, int bm, int rm){
    int i = b+r;
    if(i == n){
        if(bm == 0 && rm == 0)return abs(b-r);
        return big;
    }
    if(CC[b][r][bm][rm] == cc)return DP[b][r][bm][rm];
    int x = s[i]-'0';

    int ans = dp(b+1, r, (10*bm+x)%B, rm);
    int nxt = 0;

    int ans2 =dp(b, r+1, bm, (10*rm+x)%R);
    if(ans2 < ans){
        ans = ans2;
        nxt = 1;
    }

    DP[b][r][bm][rm] = ans;
    CC[b][r][bm][rm] = cc;
    next_state[b][r][bm][rm] =nxt;
    return ans;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n >> R >> B;
        cin >> s;
        cc++;

        int ans = dp(0, 0, 0, 0);
        if(ans >= n){
            cout << "-1\n";
            continue;
        }

        int b = 0;
        int r = 0;
        int bm = 0;
        int rm = 0;

        string BR = "BR";
        string res = "";

        for(int c1 = 0; c1 < n; c1++){
            res += BR[next_state[b][r][bm][rm]];
            int x = s[c1]-'0';
            if(next_state[b][r][bm][rm] == 0){
                b++;
                bm = (10*bm+x)%B;
            }
            else{
                r++;
                rm = (10*rm+x)%R;
            }
        }
        cout << res << "\n";


    }


    return 0;
}
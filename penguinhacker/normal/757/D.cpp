#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 76, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

const int MAXD = 20;

int n, nxt[MAXN];
string s;
int dp[MAXN][1<<MAXD];

void solve(){
    cin >> n >> s;
    nxt[n] = n;
    for (int i = n-1; i >= 0; i--) {
        nxt[i] = (s[i] == '1' ? i : nxt[i+1]);
    }
    for (int j = 1; j < (1<<MAXD); j++) if (__builtin_popcount(j+1) == 1) dp[n][j]++;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 1; j < (1<<MAXD); j++) if (__builtin_popcount(j+1) == 1) dp[i][j]++;
        for (int j = nxt[i]+1, c = 0; j <= min(n, nxt[i]+5); j++, c *= 2) {
            c += s[j-1]=='1';
            if (c <= 20) {
                for (int k = 0; k < (1<<20); k++) {
                    dp[i][k] += dp[j][k | (1<<(c-1))];
                    dp[i][k] %= MOD;
                }
            } else break;
        }
    }
    ll ans=0;
    for (int i = 0; i < n; i++) ans += dp[i][0], ans %= MOD;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
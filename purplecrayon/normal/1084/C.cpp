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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int n, nxt[MAXN][2];
string s;
ll dp[MAXN];

void solve(){
    cin >> s, n = sz(s);
    memset(nxt, -1, sizeof(nxt));
    for (int i = n-1; i >= 0; i--) {
        nxt[i][0] = nxt[i+1][0], nxt[i][1] = nxt[i+1][1];

        if (s[i] <= 'b') {
            nxt[i][s[i]-'a'] = i;
        }
    }
    vector<int> pos; pos.reserve(n);
    for (int i = 0; i < n; i++) if (s[i] == 'a') pos.push_back(i);
    for (int i = sz(pos)-1; i >= 0; i--) {
        dp[i] = 1;
        int c = pos[i];

        if (nxt[c][1] != -1) {
            int v = lower_bound(pos.begin(), pos.end(), nxt[c][1])-pos.begin();
            if (v < sz(pos)) dp[i] += dp[v];
            dp[i] %= MOD;
        }

        dp[i] += dp[i+1];
        dp[i] %= MOD;
    }
    cout << dp[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
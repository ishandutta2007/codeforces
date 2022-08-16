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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;


ll get(ll a, ll b) {
    const int MAXD = 32;
    a++, b++;

    ll dp[MAXD+1][2][2]={}; //already less for a, already less for b
    dp[MAXD][0][0] = 1;
    for (int i = MAXD-1; i >= 0; i--) {
        for (int j : {0, 1}) for (int k : {0, 1}) {
            for (int b1 : {0, 1}) for (int b2 : {0, 1}) if ((b1&b2)==0) {
                int cb1 = (a>>i)&1, cb2 = (b>>i)&1;
                if (!j && !cb1 && b1) continue;
                if (!k && !cb2 && b2) continue;
                dp[i][j | (b1 < cb1)][k | (b2 < cb2)] += dp[i+1][j][k];
            }
        }
    }
    return dp[0][1][1];
}
void solve(){
    ll l, r; cin >> l >> r;
    cout << get(r, r)-get(l-1, r)-get(r, l-1)+get(l-1, l-1) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}
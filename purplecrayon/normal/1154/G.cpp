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
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

const int MAXV = 1e7+10;
int n, cur[21];
short cnt[MAXV];

void solve(){
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    vector<int> val; val.reserve(n);
    while (n--) { int a; cin >> a; cnt[a]++; cnt[a] = min(cnt[a], short(2)); val.push_back(a); }

    ar<ll, 3> ans=ar<ll, 3>{ll(1e18), -1, -1};
    for (int g = 1; g < MAXV; g++) {
        int p = 0;
        for (int i = g; i < MAXV && p < 2; i += g) {
            int c=cnt[i];
            while (c--) cur[p++] = i;

        }
        if (p < 2) continue;
        ans = min(ans, {ll(cur[0])*ll(cur[1])/ll(g), cur[0], cur[1]});
    }
    for (int i = 0; i < sz(val); i++) {
        if (val[i] == ans[1]) {
            cout << i+1 << ' ';
            ans[1] = -1;
            continue;
        }
        if (val[i] == ans[2]) {
            cout << i+1 << ' ';
            ans[2] = -1;
            continue;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
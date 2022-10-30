#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>

mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7;
const int N = (1 << 19);

void run() {
    int n, m;
    cin >> n >> m;
    string s;
    map<string, pair<pii, int>> c;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m-1; ++j) {
            c[s.substr(j, 2)] = {mp(j, j+1), i};
            if (j+2 < m) c[s.substr(j, 3)] = {mp(j, j+2), i};
        }
    }
    cin >> s;
    vector<bool> bad(m);
    for (int i = 0; i < m-1; ++i) {
        if (!c.count(s.substr(i, 2))) bad[i] = true;
    }
    vector<int> dp(m+1); dp[m] = m;
    for (int i = m-2; i >= 0; --i) {
        if (c.count(s.substr(i, 2)) && dp[i+2] > 0) dp[i] = i+2;
        if (i < m-2 && c.count(s.substr(i, 3)) && dp[i+3] > 0) dp[i] = i+3;
    }
    if (dp[0] == 0) cout << -1 << endl;
    else {
        vector<pair<pii, int>> res; int v = 0;
        while (v < m)
            res.pb(c[s.substr(v, dp[v]-v)]), v = dp[v];
        cout << size(res) << endl;
        for (auto i : res) {
            cout << i.fi.fi+1 << " " << i.fi.se+1 << " " << i.se+1 << endl;
        }
    }
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}
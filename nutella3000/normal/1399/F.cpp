#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;
const int max_n = 6001;
int n;
int dp[max_n][max_n];
vector<int> r[max_n];

void solve() {
    cin >> n;

    vector<int> temp1;
    vector<pii> lines;

    for(int i = 0;i < n;i++) {
        r[i * 2].clear();
        r[i * 2 + 1].clear();
        int v1, v2;
        cin >> v1 >> v2;
        lines.emplace_back(v1, v2);
        temp1.emplace_back(v1);
        temp1.emplace_back(v2);
    }

    sort(all(temp1));

    for(int i = 0;i < n;i++) {
        int left = lower_bound(all(temp1), lines[i].fi) - temp1.begin();
        int right = lower_bound(all(temp1), lines[i].se) - temp1.begin();
        //cout << left << " " << right << endl;
        r[left].emplace_back(right);
    }

    for(int le = 2 * n - 1;le >= 0;le--) {
            for(int ri = le;ri <= 2 * n - 1;ri++) {
            int cnt = 0;
            for(int i : r[le]) 
                if (i == ri) cnt++;

            dp[le][ri] = cnt + (le == ri ? 0 : dp[le + 1][ri]);
            for(int i : r[le]) {
                if (i < ri)
                    dp[le][ri] = max(dp[le][ri], dp[le][i] + dp[i + 1][ri] + cnt);
            }
        }
    }

    cout << dp[0][2 * n - 1] << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}
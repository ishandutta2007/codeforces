#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 200001;
ll md = 1000000007;



void solve() {
    vector<ll> pw(33, 0);
    ll pwc = 1;
    range(i, 33) {
        pw[i] = pwc;
        pwc = pwc * 2 % md;
    }
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    range(i, n) cin >> s[i];
    vector<pair<int, int>> c(m);
    range(i, m) {
        cin >> c[i].first >> c[i].second;
    }
    vector<vector<int>> x(n + 1);
    range(i, n) {
        x[s[i]].push_back(i);
    }
    int ans = 0;
    ll sp = 0;
    c.emplace_back(0, 1);
    x[0].push_back(-1);
    range(i, m + 1) {
        int f = c[i].first;
        int h = c[i].second;
        if (x[f].size() < h) {
            continue;
        }
        int xcur = x[f][h - 1];
        vector<int> cc(n + 1, 0), cc2(n + 1, 0);
        if (f) cc[f] = 1;
        ll cursp = 1;
        range(j, m) {
            if (i == j) continue;
            int fj = c[j].first;
            int hj = c[j].second;
            if (x[fj].size() < hj) continue;
            if (x[fj][hj - 1] < xcur && fj != f) {
                cc[fj]++;
            }
            if (x[fj][x[fj].size() - hj] > xcur) {
                cc2[fj]++;
            }
        }
        int cans = 0;
        range(j, n + 1) {
            if (j == f) {
                if (cc[j]) cans++;
                if (cc2[j]) cans++;
                continue;
            }
            if (cc[j] || cc2[j]) {
                cans++;
            }
            if (cc[j] && cc2[j] && max(cc[j], cc2[j]) >= 2) cans++;
        }
        if (cans > ans) {
            ans = cans;
            sp = 0;
        }
        if (ans == cans) {
            range(j, n + 1) {
                if (j == f) {
                    cursp = cursp * max(1, cc2[j]) % md;
                } else {
                    int mi = min(cc[j], cc2[j]);
                    int ma = max(cc[j], cc2[j]);
                    if (mi == 0) cursp = cursp * max(ma, 1) % md;
                    else if (ma == mi && ma == 1) cursp = cursp * 2 % md;
                    else cursp = cursp * mi * max(1, (ma - 1)) % md;
                }
            }
            sp = (sp + cursp) % md;
        }
    }
    cout << ans << " " << sp;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
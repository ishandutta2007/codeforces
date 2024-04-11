#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int di[4] = {0, 0, 1, -1};
int dj[4] = {-1, 1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> t(n, vector<int>(m));
    range(i, n) range(j, m) {
            char x;
            cin >> x;
            if (x == '#') t[i][j] = 1;
            else t[i][j] = 0;
        }
    bool fr = false, fc = false;
    range(i, n) {
        bool used = false;
        for (int j = 1; j < m; ++j) {
            if (used && t[i][j]) {
                cout << "-1\n";
                return;
            }
            if (t[i][j - 1] && !t[i][j]) {
                used = true;
            }
        }
        if (!used && !t[i][m-1]) {
            fr = true;
        }
    }
    range(j, m) {
        bool used = false;
        for (int i = 1; i < n; ++i) {
            if (used && t[i][j]) {
                cout << "-1\n";
                return;
            }
            if (t[i - 1][j] && !t[i][j]) {
                used = true;
            }
        }
        if (!used && !t[n-1][j]) {
            fc = true;
        }
    }
    if (fc != fr) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> used(n, vector<int>(m));
    function<void(int, int)> dfs = [&](int i, int j) {
        used[i][j] = 1;
        range(w, 4) {
            int newi = i + di[w];
            int newj = j + dj[w];
            if (newi < 0 || newi >= n) continue;
            if (newj < 0 || newj >= m) continue;
            if (!used[newi][newj] && t[newi][newj]) dfs(newi, newj);
        }
    };
    int ans = 0;
    range(i, n) range(j, m) {
        if (!used[i][j] && t[i][j]) {
            ans++;
            dfs(i, j);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
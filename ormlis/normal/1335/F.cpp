#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int di[4] = {0, 0, -1, 1}, dj[4] = {-1, 1, 0, 0};
vector<vector<int>> used;
vector<vector<int>> ccolor;
vector<vector<pair<int, int>>> tocycle;
vector<vector<int>> c;
vector<vector<int>> t;
int sz = -1;
pair<int, int> fnd = {-1, -1};
vector<pair<int, int>> cycle_last;
void dfs(int i, int j) {
    used[i][j] = 1;
    int i2 = i + di[t[i][j]];
    int j2 = j + dj[t[i][j]];
    if (!used[i2][j2]) {
        dfs(i2, j2);
    } else if (used[i2][j2] == 1) {
        sz++;
        cycle_last.emplace_back(i, j);
        ccolor.push_back({0});
        if (c[i][j]) ccolor[sz][0] = 1;
        used[i][j] = 2;
        fnd = {i2, j2};
        return;
    }
    if (fnd.first != -1) {
        ccolor.back().push_back(0);
        if (c[i][j]) ccolor[sz][cycle_last.size()] = 1;
        cycle_last.emplace_back(i, j);
        if (fnd == make_pair(i, j)) {
            reverse(all(cycle_last));
            reverse(all(ccolor.back()));
            range(e, cycle_last.size()) {
                auto p = cycle_last[e];
                tocycle[p.first][p.second] = {sz, e};
            }
            fnd = {-1, -1};
            cycle_last.clear();
        }
        used[i][j] = 2;
        return;
    }
    int cyc = tocycle[i2][j2].first;
    int pos = (tocycle[i2][j2].second - 1 + (int) ccolor[cyc].size()) % ((int) ccolor[cyc].size());
    if (c[i][j] && !ccolor[cyc][pos]) {
        ccolor[cyc][pos] = 1;
    }
    tocycle[i][j] = {cyc, pos};
    used[i][j] = 2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    c.clear();
    c.resize(n, vector<int>(m));
    t.clear();
    t.resize(n, vector<int>(m));
    tocycle.clear();
    tocycle.resize(n, vector<pair<int, int>>(m, {-1, -1}));
    ccolor.clear();
    cycle_last.clear();
    used.clear();
    used.resize(n, vector<int>(m));
    sz = -1;
    fnd = {-1, -1};
    range(i, n) range(j, m) {
            char s;
            cin >> s;
            if (s == '0') c[i][j] = 1;
        }
    range(i, n) range(j, m) {
            char s;
            cin >> s;
            if (s == 'U') t[i][j] = 2;
            if (s == 'R') t[i][j] = 1;
            if (s == 'L') t[i][j] = 0;
            if (s == 'D') t[i][j] = 3;
        }

    vector<vector<int>> degin(n, vector<int>(m));
    range(i, n) range(j, m) {
            degin[i + di[t[i][j]]][j + dj[t[i][j]]]++;
        }

    range(i, n) {
        range(j, m)
            if (degin[i][j] == 0) {
                dfs(i, j);
            }
    }
    range(i, n) {
        range(j, m) {
            if (!used[i][j]) {
                dfs(i, j);
            }
        }
    }
    int ans = 0, ans2 = 0;
    range(i, (int)ccolor.size()) {
        range(j, (int)ccolor[i].size()) {
            ans++;
            ans2 += ccolor[i][j];
        }
    }
    cout << ans << " " << ans2 << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
char s[N][N];
int a[N][N];

vector<vector<pair<int, int>>> res;

void solve(vector<pair<int, int>> &ls) {
    int cnt = 0;
    vector<pair<int, int>> now;
    if (a[ls[0].first][ls[0].second]) {
        a[ls[0].first][ls[0].second] ^= 1;
        cnt++;
        now.push_back(ls[0]);
    }
    if (a[ls[1].first][ls[1].second]) {
        a[ls[1].first][ls[1].second] ^= 1;
        cnt++;
        now.push_back(ls[1]);
    }
    if (cnt) {
        for (int i = 2; i < ls.size() && cnt < 3; i++) {
            a[ls[i].first][ls[i].second] ^= 1;
            cnt++;
            now.push_back(ls[i]);
        }
        res.push_back(now);
    }
}

void solveSpecial(vector<pair<int, int>> &ls) {
    sort(ls.begin(), ls.end(), [&](pair<int, int> u, pair<int, int> v) {
        return a[u.first][u.second] > a[v.first][v.second];
    });
    int cnt = 0;
    for (auto u : ls) {
        cnt += a[u.first][u.second];
    }
    if (cnt == 0) return;
    vector<pair<int, int>> now;
    if (cnt != 2) {
        for (int i = 0; i < 3; i++) {
            now.push_back(ls[i]);
            a[ls[i].first][ls[i].second] ^= 1;
        }
        res.push_back(now);
    } else if (cnt == 2) {
        for (int i = 1; i < 4; i++) {
            now.push_back(ls[i]);
            a[ls[i].first][ls[i].second] ^= 1;
        }
        res.push_back(now);
    }
    solveSpecial(ls);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        res.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (s[i] + 1);
            for (int j = 1; j <= m; j++) {
                a[i][j] = s[i][j] == '1';
            }
        }
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 1; j + 1 <= m; j += 2) {
                vector<pair<int, int>> ls;
                ls.push_back({i, j});
                ls.push_back({i, j + 1});
                ls.push_back({i + 1, j});
                ls.push_back({i + 1, j + 1});
                solve(ls);
            }
            if (m & 1) {
                vector<pair<int, int>> ls;
                ls.push_back({i, m - 1});
                ls.push_back({i, m});
                ls.push_back({i + 1, m - 1});
                ls.push_back({i + 1, m});
                solve(ls);
            }
        }
        for (int j = 1; j + 2 <= m; j++) {
            vector<pair<int, int>> ls;
            ls.push_back({n - 1, j});
            ls.push_back({n, j});
            ls.push_back({n - 1, j + 1});
            ls.push_back({n, j + 1});
            solve(ls);
        }
        vector<pair<int, int>> ls;
        ls.push_back({n - 1, m - 1});
        ls.push_back({n, m - 1});
        ls.push_back({n - 1, m});
        ls.push_back({n, m});
        solveSpecial(ls);
        cout << res.size() << '\n';
        for (auto u : res) {
            for (auto v : u) cout << v.first << ' ' << v.second << ' ';
                cout << '\n';
        }
    }
    return 0;
}
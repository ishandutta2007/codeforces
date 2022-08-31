#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

vector<pi> g[1001][1001];
vector<vector<bool>> v(1001, vector<bool> (1001));

void dfs(pi u) {
    for (auto &x : g[u.first][u.second]) {
        if (!v[x.first][x.second]) {
            v[x.first][x.second] = true;
            dfs(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pi> drifts;
    int x, y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = 0; j < drifts.size(); j++) {
            if (drifts[j].first == x or drifts[j].second == y) {
                g[x][y].push_back(drifts[j]);
                g[drifts[j].first][drifts[j].second].push_back({x, y});
            }
        }
        drifts.push_back({x, y});
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!v[drifts[i].first][drifts[i].second]) {
            dfs(drifts[i]);
            c += 1;
        }
    }

    cout << c - 1;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

vector<pair<int,int>> v[202020];
vector<pair<int,int>> w[202020];

int ff[22][22][22][22];

int vv[22];
int cc;

void dfs(int i) {
    if (i == k+1) {
        for (int a = 1; a <= k; a++) {
            if (ff[a][vv[a]][a][vv[a]]) return;
            for (int b = a+1; b <= k; b++) {
                if (ff[a][vv[a]][b][vv[b]]) return;
            }
        }
        cc++;
        return;
    }
    for (int j = 1; j <= i; j++) {
        vv[i] = j;
        dfs(i+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 0) {
            cout << "0\n";
            return 0;
        }
        sort(v[i].begin(),v[i].end());
        int a = v[i].size();
        int b = 0;
        for (auto x : v[i]) {
            b++;
            w[x.second].push_back({a,b});
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(w[i].begin(),w[i].end());
        vector<pair<int,int>> f;
        for (int j = 0; j < w[i].size(); j++) {
            if (j != 0) {
                if (w[i][j-1] == w[i][j]) {
                    ff[w[i][j].first][w[i][j].second][w[i][j].first][w[i][j].second] = 1;
                    continue;
                }
            }
            f.push_back(w[i][j]);
        }
        for (int a = 0; a < f.size(); a++) {
            for (int b = a+1; b < f.size(); b++) {
                ff[f[a].first][f[a].second][f[b].first][f[b].second] = 1;
                ff[f[b].first][f[b].second][f[a].first][f[a].second] = 1;
            }
        }
    }
    dfs(1);
    cout << cc << "\n";
}
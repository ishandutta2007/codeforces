#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, w, h; cin >> n >> w >> h;
    map<int, vector<vector<int>>> mp;
    vector<int> g(n), p(n), t(n);
    vector<pair<int, int>> final(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i] >> p[i] >> t[i];
        mp[p[i] - t[i]].resize(2);
        mp[p[i] - t[i]][g[i] - 1].push_back(i);
        final[i] = ((g[i] == 1) ? make_pair(p[i], h) : make_pair(w, p[i]));
    }
    vector<pair<int, int>> ans(n);
    for (auto &_ : mp) {
        auto it = _.second;
        sort(it[0].begin(), it[0].end(), [&](int i, int j) {return p[i] < p[j];});
        sort(it[1].begin(), it[1].end(), [&](int i, int j) {return p[i] < p[j];});
        for (int c = 0; c < 2; ++c) {
            for (int i = 0; i < it[c].size(); ++i) {
                int up = it[!c].size(), right = it[c].size() - i - 1;
                if (up > right) {
                    ans[it[c][i]] = final[it[!c][right]];
                } else {
                    ans[it[c][i]] = final[it[c][i + up]];
                }
            }
        }
    }
    for (auto it : ans) {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}
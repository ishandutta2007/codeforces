#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> ans;
    vector<vector<int>> P(N, vector<int>(3, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> P[i][j];
        }
    }

    auto solve = [&](auto& self, vector<int> ids, int d) {
        if (d == -1) return ids[0];
        map<int, vector<int>> mp;
        for (int id : ids) {
            mp[P[id][d]].emplace_back(id);
        }
        vector<int> res;
        for (auto i : mp) {
            int cur = self(self, i.second, d - 1);
            if (cur != -1) {
                res.emplace_back(cur);
            }
        }

        for (int i = 0; i + 1 < res.size(); i += 2) {
            cout << res[i] + 1 << " " << res[i + 1] + 1 << "\n";
        }

        return (res.size() % 2 == 0 ? -1 : res.back());
    };

    vector<int> id(N);
    iota(id.begin(), id.end(), 0);
    solve(solve, id, 2);
    return 0;

}
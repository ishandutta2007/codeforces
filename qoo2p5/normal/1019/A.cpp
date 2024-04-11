#include <bits/stdc++.h>

using namespace std;

const long long LINF = (long long) 1e18 + 1e9 + 123;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << "0\n";
        return 0;
    }
    long long answer = LINF;
    vector<vector<int>> q(m);
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        p--;
        q[p].push_back(c);
    }
    for (int i = 0; i < m; i++) {
        sort(q[i].begin(), q[i].end());
    }

    for (int t = 0; t <= n; t++) {
        long long cost = 0;
        int cur_cnt = (int) q[0].size();
        vector<int> ptr(m);
        vector<int> cnt(m);
        for (int i = 1; i < m; i++) {
            cnt[i] = (int) q[i].size();
            for (int j = 0; j < (int) q[i].size() - t; j++) {
                cost += q[i][j];
                cur_cnt++;
                ptr[i]++;
                cnt[i]--;
            }
        }
        multiset<int> counts;
        for (int i = 1; i < m; i++) {
            counts.insert(cnt[i]);
        }
        vector<pair<int, int>> all;
        for (int i = 1; i < m; i++) {
            for (int j = ptr[i]; j < (int) q[i].size(); j++) {
                all.push_back({q[i][j], i});
            }
        }
        sort(all.begin(), all.end());
        int pp = 0;
        while (cur_cnt <= *counts.rbegin()) {
            auto it = all[pp++];
            counts.erase(counts.find(cnt[it.second]));
            cnt[it.second]--;
            counts.insert(cnt[it.second]);
            cur_cnt++;
            cost += it.first;
        }

        answer = min(answer, cost);
    }
    cout << answer << "\n";

    return 0;
}
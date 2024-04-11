#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>());
        vector<int> have(m, 0);
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;   
            for (int j = 0; j < k; j++) {
                int u;
                cin >> u;
                a[u - 1].push_back(i);
            }
            have[i] = k;
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int u, int v) {
            return a[u].size() < a[v].size();
        });
        int lim = (m + 1) / 2;
        vector<int> res(m, -1);
        for (int u : order) {
            // cout << "u = " << u << endl;
            vector<int> days;
            for (int day : a[u]) {
                if (have[day] != -1) {
                    days.push_back(day);
                }
            }
            sort(days.begin(), days.end(), [&](int u, int v) {
                return have[u] < have[v];
            });

            for (int i = 0; i < min(lim, (int)days.size()); i++) {
                int day = days[i];
                have[day] = -1;
                res[day] = u;
                // cout << day << ' ';
            }
            // cout << endl;
            for (int day : days) {
                if (have[day] != -1) {
                    have[day]--;
                }
            }
        }
        bool found = 0;
        for (int i = 0; i < m; i++) {
            if (have[i] != -1) {
                found = 1;
                break;
            }
        }
        if (found) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int u : res) cout << u + 1 << ' ';
                cout << '\n';
        }
    }
    return 0;
}
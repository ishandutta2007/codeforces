#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = (int) s.length();

        int w, m;
        cin >> w >> m;

        vector<int> pref(n);
        for (int i = 0; i < n; i++) {
            pref[i] = (s[i] - '0') % 9;
            if (i > 0) {
                pref[i] = (pref[i] + pref[i - 1]) % 9;
            }
        }

        auto query = [&](int l, int r) -> int {
            int ans = pref[r] + (l > 0 ? 9 - pref[l - 1] : 0);
            return ans % 9;
        };

        vector<pair<int, int>> occurrences(9, make_pair(n, n));
        for (int i = 0; i + w <= n; i++) {
            int v = query(i, i + w - 1);
            if (occurrences[v].first == n) {
                occurrences[v].first = i;
            } else if (occurrences[v].second == n) {
                occurrences[v].second = i;
            }
        }

        while (m--) {
            int l, r, k;
            cin >> l >> r >> k, --l, --r;

            int v = query(l, r);

            pair<int, int> answer(n, n);
            for (int k1 = 0; k1 < 9; k1++) {
                for (int k2 = 0; k2 < 9; k2++) {
                    if ((k1 * v + k2) % 9 != k) {
                        continue;
                    }
                    if (k1 == k2 && occurrences[k1].first != n && occurrences[k1].second != n) {
                        answer = min(answer, occurrences[k1]);
                    } else if (k1 != k2 && occurrences[k1].first != n && occurrences[k2].first != n) {
                        answer = min(answer, make_pair(occurrences[k1].first, occurrences[k2].first));
                    }
                }
            }

            if (answer.first != n && answer.second != n) {
                cout << answer.first + 1 << ' ' << answer.second + 1 << '\n';
            } else {
                cout << "-1 -1\n";
            }
        }
    }
    return 0;
}
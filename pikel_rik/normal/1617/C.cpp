#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> ranges(n);

        set<pair<int, int>, greater<>> s;
        for (int i = 0; i < n; i++) {
            ranges[i] = (a[i] == 1 ? 1 : min(n, (a[i] - 1) / 2));
            s.emplace(ranges[i], i);
        }

        vector<int> pos(n + 1, -1);
        for (int i = 0; i < n; i++) {
            if (a[i] <= n) {
                pos[a[i]] = i;
            }
        }

        int min_ops = 0;
        for (int i = n; i > 0; i--) {
            if (pos[i] != -1) {
                s.erase(make_pair(ranges[pos[i]], pos[i]));
            } else {
                auto [range, idx] = *s.begin();
                s.erase(s.begin());
                if (range < i) {
                    min_ops = -1;
                    break;
                }
                min_ops += 1;
            }
        }

        cout << min_ops << '\n';
    }
    return 0;
}
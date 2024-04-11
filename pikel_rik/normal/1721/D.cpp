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

        vector<int> b(n);
        for (auto &x : b) cin >> x;

        vector<pair<vector<int>, vector<int>>> pairs, new_pairs;
        pairs.reserve(n), new_pairs.reserve(n);

        pairs.emplace_back(move(a), move(b));

        int ans = 0;
        for (int bit = 29; bit >= 0; bit--) {
            bool possible = true;
            for (auto &[u, v] : pairs) {
                array<int, 2> cnt_u = {}, cnt_v = {};
                for (int i = 0; i < (int) u.size(); i++) {
                    cnt_u[u[i] >> bit & 1] += 1;
                    cnt_v[v[i] >> bit & 1] += 1;
                }
                possible &= cnt_u[0] == cnt_v[1] && cnt_u[1] == cnt_v[0];
            }

            if (possible) {
                ans |= 1 << bit;
                new_pairs.resize(0);
                for (auto &[u, v] : pairs) {
                    for (int set : {0, 1}) {
                        vector<int> new_u, new_v;
                        for (int i = 0; i < (int) u.size(); i++) {
                            if ((u[i] >> bit & 1) == set) {
                                new_u.push_back(u[i]);
                            }
                            if ((v[i] >> bit & 1) != set) {
                                new_v.push_back(v[i]);
                            }
                        }
                        if (!new_u.empty()) {
                            new_pairs.emplace_back(new_u, new_v);
                        }
                    }
                }
                pairs.swap(new_pairs);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
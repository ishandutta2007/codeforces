#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int inf = (int) 2e9;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        struct segment { int l, r, c; };

        vector<segment> segments(n);
        for (auto &[l, r, c] : segments) cin >> l >> r >> c, --c;

        vector<int> ans(n, inf);

        for (int rot = 0; rot < 2; rot++) {
            map<int, pair<vector<int>, vector<int>>> mp;
            for (int i = 0; i < n; i++) {
                auto &[l, r, c] = segments[i];
                mp[l].first.push_back(i);
                mp[r].second.push_back(i);
            }

            set<int> active;
            vector<int> is_active(n);

            multiset<int, greater<>> s;
            vector<int> last_r(n);

            for (auto &[x, p] : mp) {
                auto &[add, rem] = p;
                for (int i : add) {
                    if (++is_active[segments[i].c] == 1) {
                        active.insert(segments[i].c);
                    }
                }

                for (int i : add) {
                    if ((!active.empty() && *active.begin() != segments[i].c) || active.size() > 1) {
                        ans[i] = 0;
                    } else if (!s.empty()) {
                        if (*s.begin() != last_r[segments[i].c]) {
                            ans[i] = min(ans[i], x - *s.begin());
                        } else if (s.size() > 1) {
                            ans[i] = min(ans[i], x - *next(s.begin()));
                        }
                    }
                }

                for (int i : rem) {
                    if (!s.empty()) {
                        if (*s.begin() != last_r[segments[i].c] && *s.begin() >= segments[i].l) {
                            ans[i] = 0;
                        } else if (*s.begin() == last_r[segments[i].c] && s.size() > 1 && *next(s.begin()) >= segments[i].l) {
                            ans[i] = 0;
                        }
                    }
                    if (active.size() > 1 || *active.begin() != segments[i].c) {
                        ans[i] = 0;
                    }
                }

                for (int i : rem) {
                    if (last_r[segments[i].c] != 0) {
                        s.erase(s.find(last_r[segments[i].c]));
                    }
                    last_r[segments[i].c] = x;
                    s.insert(last_r[segments[i].c]);
                    if (--is_active[segments[i].c] == 0) {
                        active.erase(segments[i].c);
                    }
                }
            }

            for (auto &[l, r, c] : segments) {
                swap(l, r);
                l = (int) 1e9 + 1 - l;
                r = (int) 1e9 + 1 - r;
            }
        }

        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
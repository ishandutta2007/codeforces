#include <bits/stdc++.h>
using namespace std;

template <typename F>
vector<int> left(const vector<int> &a, F &&f) {
    int n = (int) a.size();
    vector<int> st, l(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && f(a[st.back()], a[i])) {
            st.pop_back();
        }
        if (!st.empty()) {
            l[i] = st.back();
        }
        st.push_back(i);
    }
    return l;
}

template <typename F>
vector<int> right(const vector<int> &a, F &&f) {
    int n = (int) a.size();
    vector<int> st, r(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && f(a[st.back()], a[i])) {
            st.pop_back();
        }
        if (!st.empty()) {
            r[i] = st.back();
        }
        st.push_back(i);
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int N = 1e6;

    vector<vector<int>> divisors(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }

    vector<vector<int>> pos(N + 1);
    vector<int> last(N + 1, -1);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        auto ls = left(a, [](int x, int y) { return x >= y; });
        auto rs = right(a, [](int x, int y) { return x >= y; });
        auto lg = left(a, [](int x, int y) { return x < y; });
        auto rg = right(a, [](int x, int y) { return x <= y; });

        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (pos[a[i]].back() == i) {
                reverse(pos[a[i]].begin(), pos[a[i]].end());
            }
        }

        long long ans = 0;
        for (int i = 0, len = 0; i < n; i++) {
            if (i == 0 || a[i] == a[i - 1]) {
                len += 1;
            } else if (a[i] != a[i - 1]) {
                len = 1;
            }
            ans += len;
        }

        for (int i = 0; i < n; i++) {
            for (int d : divisors[a[i]]) {
                if (d == a[i] || (last[d] == -1 && pos[d].empty())) {
                    continue;
                }

                int left_pos = last[d];
                int right_pos = (pos[d].empty() ? n : pos[d].back());
                int therel = 0, notl = 0;
                int therer = n - 1, notr = n - 1;

                if (left_pos != -1 && rs[left_pos] > i) {
                    therel = ls[left_pos] + 1;
                    notl = left_pos + 1;
                }
                if (right_pos != n && ls[right_pos] < i) {
                    therer = rs[right_pos] - 1;
                    notr = right_pos - 1;
                }

                therel = max(therel, lg[i] + 1);
                notl = max(notl, lg[i] + 1);
                therer = min(therer, rg[i] - 1);
                notr = min(notr, rg[i] - 1);

                if (left_pos != -1 && rs[left_pos] > i) {
                    therer = min(therer, rs[left_pos] - 1);
                    notr = min(notr, rs[left_pos] - 1);
                }
                if (right_pos != n && ls[right_pos] < i) {
                    therel = max(therel, ls[right_pos] + 1);
                    notl = max(notl, ls[right_pos] + 1);
                }

                ans += (i - therel + 1ll) * (therer - i + 1ll)  - (i - notl + 1ll) * (notr - i + 1ll);
//                cout << i << ' ' << a[i] << ' ' << d <<  '\n';
//                cout << therel << ' ' << notl << ' ' << notr << ' ' << therer << '\n';
            }
            last[a[i]] = i;
            pos[a[i]].pop_back();
        }

        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            last[a[i]] = -1;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string c;
    cin >> c;

    c = '$' + c;

    vector<int> l(n + 1), r(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        p[l[i]] = p[r[i]] = i;
    }

    string repr;
    vector<int> order;

    auto dfs = [&](int x, auto &&self) -> void {
        if (x != 0) {
            self(l[x], self);
            repr += c[x];
            order.push_back(x);
            self(r[x], self);
        }
    };

    dfs(1, dfs);

    vector<bool> dup(n);
    dup[order.back()] = false;

    for (int i = n - 2; i >= 0; i--) {
        if (repr[i] > repr[i + 1]) {
            dup[order[i]] = false;
        } else if (repr[i] < repr[i + 1]) {
            dup[order[i]] = true;
        } else {
            dup[order[i]] = dup[order[i + 1]];
        }
    }

    vector<bool> will_dup(n + 1);
    auto second_dfs = [&](int x, int d, auto &&self) -> void {
        if (x != 0) {
            if (dup[x] && d <= k) {
                k -= d, d = 0;
                will_dup[x] = true;
            }
            self(l[x], d + 1, self);
            will_dup[x] = will_dup[x] || will_dup[l[x]];
            if (will_dup[x]) {
                self(r[x], 1, self);
            }
        }
    };

    second_dfs(1, 1, second_dfs);

    string final_repr;
    for (int u : order) {
        final_repr += c[u];
        if (will_dup[u]) {
            final_repr += c[u];
        }
    }

    cout << final_repr << '\n';
    return 0;
}
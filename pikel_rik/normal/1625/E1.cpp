#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    auto f = [](long long x) -> long long {
        return (x * x + x) / 2;
    };

    vector<int> depth(n);
    vector<vector<int>> pos(n, {-1});
    vector<vector<long long>> prefix(n, {0});

    auto query = [&](int l, int r) -> long long {
        int d = depth[r];

        auto ub = upper_bound(pos[d].begin(), pos[d].end(), r) - pos[d].begin();
        auto lb = upper_bound(pos[d].begin(), pos[d].end(), l) - pos[d].begin();

        int between = ub - lb;
        long long inside_between = prefix[d][ub - 1] - prefix[d][lb - 1];

        return f(between) + inside_between;
    };

    vector<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push_back(i);
        } else if (s[i] == ')' && !st.empty()) {
            int l = st.back(), r = i;
            st.pop_back();

            depth[r] = (int) st.size();
            pos[depth[r]].push_back(r);

            if (l + 1 != r) {
                prefix[depth[r]].push_back(query(l + 1, r - 1) + prefix[depth[r]].back());
            } else {
                prefix[depth[r]].push_back(prefix[depth[r]].back());
            }
        }
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r, --l, --r;

        cout << query(l, r) << '\n';
    }
    return 0;
}
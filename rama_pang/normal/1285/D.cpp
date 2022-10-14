#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    function<int(int, vector<int>)> solve = [&](int bit, vector<int> a) {
        if (a.size() == 0) {
            return 0;
        }
        if (bit < 0) {
            return 0;
        }
        vector<int> a0, a1;
        for (auto &i : a) {
            if (i & (1 << bit)) {
                a1.emplace_back(i);
            } else {
                a0.emplace_back(i);
            }
        }
        if (a1.empty()) {
            return solve(bit - 1, a0);
        }
        if (a0.empty()) {
            return solve(bit - 1, a1);
        }
        return (1 << bit) + min(solve(bit - 1, a0), solve(bit - 1, a1));
    };

    cout << solve(30, a) << "\n";

    return 0;
}
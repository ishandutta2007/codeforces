#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    auto choose = [](int n) -> int {
        return (n * n + n) / 2;
    };

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (auto &x : b) cin >> x;

        long long sum_a = accumulate(b.begin(), b.end(), 0ll);

        if (sum_a % choose(n) != 0) {
            cout << "NO\n";
            continue;
        }

        sum_a /= choose(n);

        vector<int> a(n, -1);
        for (int i = 0; i < n; i++) {
            int j = (i == 0 ? n - 1 : i - 1);
            //b[i] - b[j] = sum_a - n * a[i]
            int temp = sum_a - b[i] + b[j];
            if (temp > 0 && temp % n == 0) {
                a[i] = temp / n;
            }
        }

        if (count(a.begin(), a.end(), -1)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (auto &x : a) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
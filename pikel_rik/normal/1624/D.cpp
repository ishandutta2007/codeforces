#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        array<int, 26> cnt = {};
        for (auto ch : s) {
            cnt[ch - 'a'] += 1;
        }

        int pairs = 0;
        for (auto c : cnt) {
            pairs += c / 2;
        }

        auto f = [&](int len) -> bool {
            return k * (len / 2) <= pairs;
        };

        int lo = 1, hi = n / k;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (f(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}
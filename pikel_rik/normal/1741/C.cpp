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

        partial_sum(a.begin(), a.end(), a.begin());

        int sum = a.back();

        vector<int> divisors;
        for (int i = 1; i * i <= sum; i++) {
            if (sum % i == 0) {
                divisors.push_back(i);
                if (sum / i != i) {
                    divisors.push_back(sum / i);
                }
            }
        }

        int minimum_thickness = n;
        for (int d : divisors) {
            int longest_segment = 0;
            for (int i = 0, cur = 0; i < n;) {
                int j = find(a.begin() + i, a.end(), cur + d) - a.begin();
                if (j == n) {
                    longest_segment = 0;
                    break;
                }
                longest_segment = max(longest_segment, j - i + 1);
                i = j + 1;
                cur += d;
            }

            if (longest_segment != 0) {
                minimum_thickness = min(minimum_thickness, longest_segment);
            }
        }

        cout << minimum_thickness << '\n';
    }
    return 0;
}
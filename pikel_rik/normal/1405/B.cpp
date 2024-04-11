#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& i : a) cin >> i;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0) {
                sum += a[i];
                a[i] = 0;
            } else {
                a[i] = abs(a[i]);
                if (a[i] < sum) {
                    sum -= a[i];
                    a[i] = 0;
                } else {
                    a[i] -= sum;
                    sum = 0;
                }
            }
        }

        cout << (sum + accumulate(a.begin(), a.end(), 0ll)) / 2 << '\n';
    }
    return 0;
}
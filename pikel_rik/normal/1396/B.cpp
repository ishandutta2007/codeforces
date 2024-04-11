#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

bitset<10001> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int sum = accumulate(a.begin(), a.end(), 0);

        bool flag = false;
        for (int i = 0; i < n; i++) {
            flag |= (a[i] > sum - a[i]);
        }

        if (flag) {
            cout << "T\n";
            continue;
        }

        b[0] = true;
        for (int i = 1; i <= 10000; i++) b[i] = false;
        for (int i = 0; i < n; i++) b |= b << a[i];

        int i;
        for (i = sum / 2; !b[i]; i--) {}

        if ((sum - 2 * i) & 1)
            cout << "T\n";
        else cout << "HL\n";
    }
    return 0;
}
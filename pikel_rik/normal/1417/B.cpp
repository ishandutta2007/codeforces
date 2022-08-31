#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, T;
        cin >> n >> T;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> p(n);
        int last = 0;

        for (int i = 0; i < n; i++) {
            if (T % 2 == 0 and a[i] == T / 2) {
                p[i] = last;
                last = 1 - last;
            } else if (a[i] <= T / 2) {
                p[i] = 0;
            } else {
                p[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
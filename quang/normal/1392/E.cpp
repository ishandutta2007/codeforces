#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n;
long long a[N][N];

int main() {
    cin >> n;   
    for (int sum = 0; sum <= 2 * (n - 1); sum++) {
        long long val = 1ll << sum;
        for (int i = 0; i < n; i++) {
            int j = sum - i;
            if (j < 0 || j >= n) continue;
            if (i & 1) a[i][j] = val;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        int u = 0, v = 0;
        vector<pair<int, int>> res;
        res.push_back({u, v});
        for (int sum = 1; sum <= 2 * (n - 1); sum++) {
            int needOdd = 0;
            if (k >> sum & 1ll) {
                needOdd = 1;
            }
            if (u % 2 != needOdd) u++;
            else v++;
            res.push_back({u, v});
        }
        for (auto x : res) {
            cout << x.first + 1 << ' ' << x.second  + 1 << '\n';
        }
    }
    return 0;
}
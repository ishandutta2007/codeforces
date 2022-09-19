#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> p(2 * k + 2);

    for (int i = 0; i < n / 2; i++) {
        int x = a[i];
        int y = a[n - 1 - i];
        p[x + y] += 1;
        p[2 * k + 1] += 1;
        p[x + y + 1] -= 1;
        p[2 * k + 1] += 1;
        p[k + max(x, y) + 1] -=1;
        p[min(x, y) + 1] += 1;
//        for (int x : p) {
//            cout << x << " ";
//        }
//        cout << "\n";
    }

    vector<int> s(2 * k + 2);
    int res = INT_MAX;
    for (int i = 2 * k; i >= 2; i--) {
        s[i] = s[i + 1] + p[i + 1];
        res = min(res, s[i]);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}
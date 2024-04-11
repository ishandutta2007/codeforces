#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < n; i++) s2 += (1 - a[i]);
        int res = n;
        for (int i = 0; i <= n; i++) {
            res = min(res, max(s1, s2));
            if (i < n) {
                s1 += a[i];
                s2 -= (1 - a[i]);
            }
        }
        cout << res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}
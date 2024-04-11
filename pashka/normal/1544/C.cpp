#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve_test() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int l = -1;
        int r = n * 3;
        while (r > l + 1) {
            int m = (l + r) / 2;
            int k = n + m;
            int kk = k - k / 4;
            long s1 = 0;
            long s2 = 0;
            for (int i = k - 1; i >= k - kk; i--) {
                if (i >= n) {
                    s1 += 100;
                } else {
                    s1 += a[i];
                }
            }
            for (int i = n - 1; i >= n - kk; i--) {
                if (i >= 0) {
                    s2 += b[i];
                } else {
                    break;
                }
            }
            if (s1 >= s2) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << "\n";
    }
};


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve_test();
    }

    return 0;
}
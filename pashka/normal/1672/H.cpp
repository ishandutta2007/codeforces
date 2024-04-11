#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> p0(n + 1);
        vector<int> p1(n + 1);
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                if (s[i] == '0')
                    p0[i + 1] = 1;
                else
                    p1[i + 1] = 1;
            }
        }
        for (int i = 1; i <= n; i++) p0[i] += p0[i - 1];
        for (int i = 1; i <= n; i++) p1[i] += p1[i - 1];
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            int c0 = p0[r - 1] - p0[l];
            int c1 = p1[r - 1] - p1[l];
            int x = min(c0, c1);
            int y = max(c0, c1) - x;
            cout << x + y + 1 << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
        test().solve();
//    }

    return 0;
}
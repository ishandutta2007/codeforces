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
        long s = 0;
        for (int i = 1; i < n - 1; i++) s += a[i];
        int c1 = 0;
        int codd = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] == 1) c1++;
            if (a[i] % 2 == 1) codd++;
        }
        if (c1 == n - 2) {
            cout << "-1\n";
            return;
        }
        if (n == 3 && codd == 1) {
            cout << "-1\n";
            return;
        }
        cout << (s + codd) / 2 << "\n";
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
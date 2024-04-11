#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> c(n + 1);
        int i = n - 1;
        int j = n - 1;
        while (j > 0) {
            if (a[i] == b[j]) {
                i--;
                j--;
                continue;
            }
            if (j < n - 1 && b[j] == b[j + 1]) {
                c[b[j]]++;
                j--;
                continue;
            }
            if (c[a[i]] > 0) {
                c[a[i]]--;
                i--;
                continue;
            }
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
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
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
        vector<pair<int, int>> b;
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] < a[i]) {
                b.emplace_back(a[i] - a[i + 1], i + 2);
            }
        }
        sort(b.rbegin(), b.rend());
        vector<int> res(n, n);
        for (int i = 0; i < b.size(); i++) {
            res[n - 1 - i] = b[i].second;
        }
        for (int x : res) cout << x << " ";
        cout << "\n";
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
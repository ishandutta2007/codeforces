#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int solve();
// #define TESTCASE
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifdef TESTCASE
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}

int solve() {
    
    int n;
    cin >> n;
    vector<int> a(n - 1), b(n - 1, -1), deg(n);
    for (int i = 0; i + 1 < n; i++) {
        cin >> a[i];
        a[i]--;
        deg[a[i]]++;
    }

    int root = a[0];
    set<int> leaf;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            leaf.emplace(i);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        b[i] = *leaf.begin();
        leaf.erase(b[i]);
        deg[a[i]]--;
        if (deg[a[i]] == 0) {
            leaf.emplace(a[i]);
        }
    }

    cout << root + 1 << "\n";
    for (int i = 0; i + 1 < n; i++) {
        cout << a[i] + 1 << " " << b[i] + 1 << "\n";
    }

    return 0;
}
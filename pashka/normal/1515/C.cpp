#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<pair<int, int>> z;
    for (int i = 0; i < m; i++) z.insert({0, i});
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        auto p = *z.begin();
        cout << p.second + 1 << " ";
        z.erase(p);
        z.insert({p.first + a[i], p.second});
    }
    cout << "\n";
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
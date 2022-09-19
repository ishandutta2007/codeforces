#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x; x--;
        cout << a[x % n] << b[x % m] << "\n";
    }

    return 0;
}
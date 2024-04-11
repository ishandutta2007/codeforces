#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    cout << a.back() << " " << b.back() << "\n";
    return 0;
}
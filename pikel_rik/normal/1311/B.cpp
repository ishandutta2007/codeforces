#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i], --b[i];

        vector<int> mark(n);
        for (int i = 0; i < m; i++) {
            mark[b[i]] = 1;
        }

        int last = -1;
        for (int i = 0; i < n; i++) {
            if (!mark[i]) {
                if (last != i - 1)
                    sort(a.begin() + last + 1, a.begin() + i + 1);
                last = i;
            }
        }

        if (last != n - 1)
            sort(a.begin() + last + 1, a.begin() + n);

        if (is_sorted(a.begin(), a.end()))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
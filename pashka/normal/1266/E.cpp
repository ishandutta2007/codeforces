#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long> d(n);
    long res = 0;
    for (int i = 0; i < n; i++) res += a[i];
    int m;
    cin >> m;
    map<pair<int, int>, int> e;
    for (int i = 0; i < m; i++) {
        int s, t, u;
        cin >> s >> t >> u;
        s--;
        u--;
        if (e.find({s, t}) != e.end()) {
            int uu = e[{s, t}];
            d[uu]--;
            if (d[uu] < a[uu]) res++;
            e.erase({s, t});
        }
        if (u >= 0) {
            e[{s, t}] = u;
            d[u]++;
            if (d[u] <= a[u]) res--;
        }
        cout << res << "\n";
    }

    return 0;
}
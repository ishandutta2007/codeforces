#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

vector<int> p;
int get(int x) {
    if (p[x] != x) p[x] = get(p[x]);
    return p[x];
}


int main() {
    ios::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, pair<int, int>>> e;

    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int x;
            cin >> x;
            x--;
            e.push_back({a[i] + b[x], {i, x + m}});
        }
    }
    p.resize(n + m);
    for (int i = 0; i < n + m; i++) p[i] = i;
    long res = 0;
    sort(e.rbegin(), e.rend());
    for (auto ee : e) {
        int x = get(ee.second.first);
        int y = get(ee.second.second);
        if (x != y) {
            p[x] = y;
        } else {
            res += ee.first;
        }
    }
    cout << res << "\n";

    return 0;
}
#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<long> s1(n);
    vector<long> s2(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x > y) swap(x, y);
        g[x].push_back(y);
        s1[x]++;
        s2[y]++;
    }
    long res = 0;
    for (int i = 0; i < n; i++) {
        res += s1[i] * s2[i];
    }
    cout << res << "\n";
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;
        for (int y : g[x]) {
            g[y].push_back(x);
            res -= s1[y] * s2[y];
            s1[y]++;
            s2[y]--;
            res += s1[y] * s2[y];
        }
        res -= s1[x] * s2[x];
        s2[x] += s1[x];
        s1[x] = 0;
        g[x].clear();
        cout << res << "\n";
    }

    return 0;
}
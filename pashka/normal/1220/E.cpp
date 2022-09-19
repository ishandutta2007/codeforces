#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

vector<vector<int>> g;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    vector<long> w(n);
    vector<long> sw(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int st;
    cin >> st;
    st--;

    vector<int> gcnt(n);

    for (int i = 0; i < n; i++) {
        gcnt[i] = g[i].size();
    }

    vector<bool> bad(n);
    vector<int> pr;
    for (int i = 0; i < n; i++) {
        if (g[i].size() < 2) {
            bad[i] = true;
            pr.push_back(i);
        }
    }

    while (!pr.empty()) {
        int x = pr.back();
        pr.pop_back();
        if (x == st) continue;
        w[x] += sw[x];
//        cout << x << "\n";
        for (int y : g[x]) {
//            cout << " " << y << "\n";
            sw[y] = max(sw[y], w[x]);
            gcnt[y]--;
            if (gcnt[y] < 2 && !bad[y]) {
                bad[y] = true;
                pr.push_back(y);
            }
        }
    }

    bad[st] = false;

//    for (int i = 0; i < n; i++) {
//        cout << bad[i] << " " << gcnt[i] << " " << w[i] << " " << sw[i] << "\n";
//    }

    long res = 0;
    long res2 = 0;
    for (int i = 0; i < n; i++) {
        if (!bad[i]) {
            res += w[i];
        }
        res2 = max(res2, sw[i]);
    }
    cout << res + res2;
    return 0;
}
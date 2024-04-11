#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int p[500000];
bool good[500000];
int get(int x) {
    if (p[x] != x) p[x] = get(p[x]);
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> res;
    int cnt = 1;
    const long MOD = 1000000007;
    for (int i = 0; i < m; i++) p[i] = i;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            x--;
            x = get(x);
            if (!good[x]) {
                cnt = cnt * 2 % MOD;
                good[x] = true;
                res.push_back(i);
            }
        } else {
            int x, y;
            cin >> x >> y;
            x--; y--;
            x = get(x);
            y = get(y);
            if (x != y && (!good[x] || !good[y])) {
                p[x] = y;
                good[y] |= good[x];
                cnt = cnt * 2 % MOD;
                res.push_back(i);
            }
        }
    }
    cout << cnt << " " << res.size() << "\n";
    for (int x : res) {
        cout << x + 1 << " ";
    }

    return 0;
}
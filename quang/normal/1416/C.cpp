#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int LOG = 30;

int n;

struct Trie {
    int child[2][N * LOG];
    int num[N * LOG];
    int cnt;
    long long inv[2][N * LOG];

    Trie() {
        cnt = 1;
        memset(child[0], 0, sizeof child[0]);
        memset(child[1], 0, sizeof child[1]);
        memset(num, 0, sizeof num);
        memset(inv[0], 0, sizeof inv[0]);
        memset(inv[1], 0, sizeof inv[1]);
    }

    int get(int u) {
        if (!u) return 0;
        return num[u];
    }

    void add(int u) {
        int cur = 1;
        for (int i = LOG - 1; i >= 0; i--) {
            int id = (u >> i) & 1;
            if (!child[id][cur]) child[id][cur] = ++cnt;
            num[cur]++;

            inv[id][i] += get(child[id ^ 1][cur]);
            cur = child[id][cur];
        }
        num[cur]++;
    }

    void solve() {
        long long res = 0;
        int x = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            // cout << i << ' ' << inv[0][i] << ' ' << inv[1][i] << endl;
            if (inv[0][i] <= inv[1][i]) {
                res += inv[0][i];
            } else {
                res += inv[1][i];
                x |= (1 << i);
            }
        }
        cout << res << ' ' << x << '\n';
    }
} t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        t.add(u);
    }
    t.solve();
    return 0;
}
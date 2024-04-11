#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    static int adj[26][26];

    while (T--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        reverse(t.begin(), t.end());

        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < n; i++) {
            int u = s[i] - 'a';
            int v = t[i] - 'a';
            if (u > v) {
                swap(u, v);
            }
            adj[u][v] += 1;
        }

        bool okay = true;
        int odd = 0;
        for (int u = 0; u < 26; u++) {
            for (int v = 0; v < 26; v++) {
                if (u != v) {
                    okay &= adj[u][v] % 2 == 0;
                } else {
                    odd += adj[u][u] % 2 != 0;
                }
            }
        }

        cout << (okay && odd == n % 2 ? "YES" : "NO") << '\n';
    }
    return 0;
}
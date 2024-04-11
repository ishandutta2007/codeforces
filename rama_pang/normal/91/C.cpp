#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;

int p[100005];
int par(int n) {
    if (p[n] == n) return n;
    return p[n] = par(p[n]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    iota(p, p + N + 1, 0);
    int ans = 1; // empty set
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (par(u) == par(v)) {
            ans = (1ll * ans * 2) % MOD;
        }
        p[par(u)] = par(v);
        cout << (ans - 1 + MOD) % MOD << "\n";
    }
    return 0;
}
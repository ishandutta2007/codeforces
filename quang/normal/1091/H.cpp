#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MAX = 100;

int n, f;
bitset<N> a[MAX];
bitset<N> b;
int p[N];
int g[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> f;
    for (int i = 2; i < N; i++) {
        if (!p[i]) {
            b[i] = 1;
            for (int j = i + i; j < N; j += i) {
                p[j] = i;
            }
        } else {
            if (!p[i / p[i]]) {
                b[i] = 1;
            }
        }
    }
    b[f] = 0;
    a[0] = b;
    for (int i = 1; i < N; i++) {
        int cur = 0;
        while (1) {
            if (!a[cur][i]) break;
            cur++;
        }
        g[i] = cur;
        a[g[i]] |= (b << i);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        res ^= g[v - u - 1] ^ g[w - v - 1];
    }
    if (res == 0) {
        cout << "Bob\nAlice\n";
    } else {
        cout << "Alice\nBob\n";
    }
    return 0;
}
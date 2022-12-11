#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int adj[N];
int n, m;

int rem[1 << 22], rem_lg2[1 << 22];
int valid[1 << 22];

int con_all[N];
int group[N];

int find_group(int x) {
    if (x == group[x]) return x;
    return group[x] = find_group(group[x]);
}

inline int lg2(int x) {
    return rem_lg2[x];
}

int main() {

    cin >> n >> m;
    for (int u = 0; u < n; ++u) {
        adj[u] = 1 << u;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u-1] |= 1 << (v-1);

        adj[v-1] |= 1 << (u-1);
    }

    for (int u = 0; u < n; ++u) {
        con_all[u] = (adj[u] == (1 << n) - 1);
    }

    valid[0] = 1;
    for (int i = 0; i < n; ++i) {
        valid[1 << i] = 1;
        rem_lg2[1 << i] = i;
    }

    for (int i = 0; i < (1 << n); ++i) {
        rem[i] = __builtin_popcount(i);
    }

    int ans = (1 << n) - 1;
    for (int i = 0; i < (1 << n); ++i) {

        for (int idx = i; idx; idx ^= idx & -idx) {
            int u = rem_lg2[idx & -idx];
            if ((adj[u] & i) == (1 << u)) continue;
            valid[i] |= valid[i ^ (idx & -idx)];
        }

        if (rem[i] >= rem[ans]) continue;
        if (!valid[i]) continue;

        bool err = false;

        for (int u = 0; u < n; ++u) {
            if (con_all[u]) continue;
            if (!(i & adj[u])) {
                err = true;
                break;
            }
        }

        if (err) continue;

        ans = i;
    }

    cout << __builtin_popcount(ans) << endl;
    for (int u = 0; u < n; ++u) {
        if ((ans >> u) & 1) {
            cout << (u+1) << " ";
        }
    }
    cout << endl;

    return 0;
}
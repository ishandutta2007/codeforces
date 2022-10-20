#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 22);

int n, m;
bool used[N];
bool has[N], inside[N];

inline int invert(int u) {
    return (1 << n) - u - 1;
}

void dfs(int u) {
    used[u] = 1;
    if (has[invert(u)]) {
        inside[invert(u)] = 1;
        if (!used[invert(u)]) {
            dfs(invert(u));
        }
    }
    for (int i = 0; i < n; i++) {
        if ((u & (1 << i)) == 0 && !used[u | (1 << i)]) {
            dfs(u | (1 << i));
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u;
        scanf("%d", &u);
        has[u] = 1;
    }
    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (has[i] && !inside[i]) {
            inside[i] = 1;
            if (!used[i]) {
                dfs(i);
            }
            res++;
            // for (int i = 0; i < (1 << n); i++) {
            //     cout << inside[i] << " ";
            // }
            // cout << endl;
        }
    }
    cout << res << endl;
    return 0;
}
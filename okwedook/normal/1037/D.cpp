#ifndef BZ
#pragma GCC optimize -O3
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = double;
using ull = uint64_t;

const int MAXN = 200228;
int p[MAXN];
int a[MAXN];

vector<int> e[MAXN];

void dfs(int v, int cp) {
    p[v] = cp;
    for (int u: e[v]) {
        if (u != cp) {
            dfs(u, v);
        }
    }
}

void no() {
    cout << "No\n";
    exit(0);
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    fill(a, a + n + 1, -1);

    int root;
    cin >> root;
    if (root != 1) {
        cout << "No";
        return 0;
    }
    a[root] = 0;
    dfs(root, 0);
    int pv = 0;

    for (int i = 1; i < n; ++i) {
        int v;
        cin >> v;
        int cur = a[p[v]];
        if (cur < pv) {
            no();
        }

        a[v] = i;

        pv = cur;
    }

    cout << "Yes\n";
}
#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const int K = 70;
const int MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

int n, m, k;
long long c[N];
int root[N];
int used[N * 2], cntUsed;
int p2[N];
pair<int, int> a[N];

bool cmp(const pair<int, int> &u, const pair<int, int> &v) {
    long long x = c[u.first] ^ c[u.second];
    long long y = c[v.first] ^ c[v.second];
    return x < y;
}

int getRoot(int u) {
    if (root[u] < 0) {
        return u;
    }
    return root[u] = getRoot(root[u]);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = add(p2[i - 1], p2[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", c + i);
        root[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a + 1, a + m + 1, cmp);
    // for (int i = 1; i <= m; i++) {
    //     cout << "value " << a[i].first << " " << a[i].second << endl;
    // }
    int numUsedVal = 0;
    int res = 0;
    for (int l = 1, r = 1; l <= m; l = r) {
        numUsedVal++;
        while (r <= m && (c[a[l].first] ^ c[a[l].second]) == (c[a[r].first] ^ c[a[r].second])) {
            r++;
        }
        cntUsed = 0;
        int numGroup = n;
        for (int i = l; i < r; i++) {
            int u = getRoot(a[i].first);
            int v = getRoot(a[i].second);
            if (u == v) {
                continue;
            }
            numGroup--;
            root[v] += root[u];
            root[u] = v;
            used[cntUsed++] = u;
            used[cntUsed++] = v;
        }
        // cout << "debug " << numGroup << " " << l << " " << a[l].first << " " << a[l].second << endl;
        res = add(res, p2[numGroup]);

        // reset data
        for (int i = 0; i < cntUsed; i++) {
            root[used[i]] = -1;
        }
    }
    // cout << sub(p2[k], numUsedVal) << endl;
    int foo = mul(sub(p2[k], numUsedVal), p2[n]);
    cout << add(foo, res) << endl;
    return 0;
}
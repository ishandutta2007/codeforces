#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5 + 100;
int arr[MAXN];
int tree[4 * MAXN];

void pull(int v) {
    tree[v] = __gcd(tree[v * 2], tree[v * 2 + 1]);
}

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tree[v] = arr[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    build(v * 2, vl, vm);
    build(v * 2 + 1, vm, vr);
    pull(v);
}

int get(int v, int vl, int vr, int l, int r) {
    if (l >= vr || r <= vl) {
        return 0;
    }
    if (l <= vl && r >= vr) {
        return tree[v];
    }
    int vm = (vl + vr) / 2;
    int res1 = get(v * 2, vl, vm, l, r);
    int res2 = get(v * 2 + 1, vm, vr, l, r);
    return __gcd(res1, res2);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            arr[i] = abs(arr[i + 1] - arr[i]);
        }

        n--;
        if (n == 0) {
            cout << 1 << "\n";
            continue;
        }
        build(1, 0, n);
        int f = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while (f <= i) {
                f++;
            }
            while (f <= n && get(1, 0, n, i, f) > 1) {
                f++;
            }
            ans = max(ans, f - i - 1);
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}
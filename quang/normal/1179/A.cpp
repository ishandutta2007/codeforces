#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q;
int a[N * 2];
pair<int, int> res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    int maxPos = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[maxPos] < a[i]) {
            maxPos = i;
        }
    }
    int tot = n;
    for (int i = 1; i < maxPos; i++) {
        res[i] = {a[i], a[i + 1]};
        if (a[i] > a[i + 1]) {
            a[++tot] = a[i + 1];
            a[i + 1] = a[i];
        } else {
            a[++tot] = a[i];
        }
    }
    for (int i = maxPos; i <= tot; i++) {
        a[i - maxPos + 1] = a[i];
    }
    while (q--) {
        long long u;
        cin >> u;
        if (u < maxPos) {
            cout << res[u].first << ' ' << res[u].second << '\n';
        } else {
            u = (u - maxPos) % (n - 1);
            cout << a[1] << ' ' << a[2 + u] << '\n';
        }
    }
    return 0;
}
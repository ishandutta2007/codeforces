#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
long long l;
long long a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > l && a[i - 1] <= l) res++;
    }
    while (m--) {
        // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        //     cout << endl;
        int op;
        cin >> op;
        if (op == 0) {
            cout << res << '\n';
        } else {
            int u, v;
            cin >> u >> v;
            long long last = a[u];
            a[u] += v;
            if (last > l) {
                continue;
            }
            if (a[u] > l) {
                res += (a[u - 1] <= l);
                res -= (a[u + 1] > l);
            }
        }
    }
    return 0;
}
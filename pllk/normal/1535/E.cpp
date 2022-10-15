#include <iostream>

using namespace std;

typedef long long ll;

int a[343434];
ll c[343434];
int e[20][343434];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q >> a[0] >> c[0];
    for (int i = 0; i < 20; i++) e[i][0] = -1;
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p >> a[i] >> c[i];
            e[0][i] = p;
            for (int k = 1; k < 20; k++) {
                e[k][i] = e[k-1][e[k-1][i]];
            }
        } else {
            int v, w;
            cin >> v >> w;
            ll m = 0;
            int h = 0;
            while (w > 0) {
                int u = v;
                for (int k = 19; k >= 0; k--) {
                    if (e[k][u] != -1 && a[e[k][u]] > 0) u = e[k][u];
                }
                if (a[u] == 0) break;
                if (w >= a[u]) {
                    m += a[u]*c[u];
                    h += a[u];
                    w -= a[u];
                    a[u] = 0;
                } else {
                    m += w*c[u];
                    h += w;
                    a[u] -= w;
                    w = 0;
                }
            }
            cout << h << " " << m << endl;
        }
    }
}
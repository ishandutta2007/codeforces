#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int LOG = 19;

int n, q;
int a[N];
int nxt[LOG][N];
int last[LOG];
int id[LOG];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < LOG; i++) last[i] = n + 1;
    for (int i = n; i; i--) {
        for (int j = 0; j < LOG; j++) {
            nxt[j][i] = n + 1;
        }
        for (int j = 0; j < LOG; j++) {
            if ((a[i] >> j) & 1) {
                nxt[j][i] = i;

                int pos = last[j];
                if (pos <= n) {
                    for (int k = 0; k < LOG; k++) {
                        nxt[k][i] = min(nxt[k][i], nxt[k][pos]);
                    }
                }
            }
        }

        for (int j = 0; j < LOG; j++) {
            if ((a[i] >> j) & 1) {
                last[j] = i;
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        int found = 0;
        for (int i = 0; i < LOG; i++) {
            if ((a[y] >> i) & 1) {
                if (nxt[i][x] <= y) {
                    found = 1;
                    break;
                }
            }
        }
        cout << (found ? "Shi" : "Fou") << '\n';
    }
    return 0;
}
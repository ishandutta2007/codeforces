#include <bits/stdc++.h>

using namespace std;

const int N = 500000;
const int MAGIC = sqrt(N);

int q;
int a[N + 10];
vector<int> val[MAGIC];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;

    for (int i = 1; i < MAGIC; i++) {
        val[i].resize(i, 0);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            a[x] += y;
            for (int i = 1; i < MAGIC; i++) {
                val[i][x % i] += y;
            }
        } else {
            int x, y;
            cin >> x >> y;
            if (x >= MAGIC) {
                int res = 0;
                for (int i = y; i <= N; i += x) {
                    res += a[i];
                }
                cout << res << '\n';
            } else {
                cout << val[x][y] << '\n';
            }
        }
    }
    return 0;
}
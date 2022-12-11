#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
const int bits = 20;

int n, q;
int a[maxn];
int d[maxn][bits];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> last(bits, n);
    for (int i = n - 1; i >= 0; --i) {
        for (int bit = 0; bit < bits; ++bit) {
            d[i][bit] = n;
            for (int k = 0; k < bits; ++k) {
                if (a[i] & (1 << k)) {
                    if (bit == k) {
                        d[i][bit] = min(d[i][bit], last[bit]);
                    } else if (last[k] < n) {
                        d[i][bit] = min(d[i][bit], d[last[k]][bit]);
                    }
                }
            }
        }
        for (int bit = 0; bit < bits; ++bit) {
            if (a[i] & (1 << bit)) {
                last[bit] = i;
            }
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        bool ok = false;
        for (int j = 0; j < bits; ++j) {
            if ((a[y] & (1 << j)) && d[x][j] <= y) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "Shi\n";
        } else {
            cout << "Fou\n";
        }
    }
}
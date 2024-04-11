#include <iostream>

using namespace std;

#define M 998244353

typedef long long ll;

int n;
int w[555];

ll d[555][555];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        if (t == "+") cin >> w[i];
    }
    ll u = 0;
    for (int x = 1; x <= n; x++) {
        // cout << "x=" << x << "\n";
        if (!w[x]) continue;
        for (int i = 0; i <= n+1; i++) {
            for (int j = 0; j <= n+1; j++) {
                d[i][j] = 0;
            }
        }
        d[1][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (d[i][j] == 0) continue;
                // cout << i << " " << j << " " << d[i][j] << "\n";
                d[i][j] %= M;
                if (i == x) {
                    d[i+1][j] += d[i][j];
                    continue;
                } else {
                    d[i+1][j] += d[i][j];
                }
                if (w[i]) {
                    if (w[i] < w[x] || (i < x && w[i] <= w[x])) d[i+1][j+1] += d[i][j];
                    else d[i+1][j] += d[i][j];
                } else {
                    if (j) d[i+1][j-1] += d[i][j];
                    else if (i < x) d[i+1][j] += d[i][j];
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            // cout << i << " " << d[n+1][i] << "\n";
            u += d[n+1][i]%M*w[x];
            u %= M;
        }
    }
    cout << u << "\n";
}
#include <iostream>

using namespace std;

int n, m, k;

int d[101][101];
int q[101];
int z[101];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        int c[101] = {0};
        for (int j = 1; j <= n; j++) {
            if (z[j]) continue;
            c[d[j][i]]++;
        }
        for (int j = 1; j <= n; j++) {
            if (d[j][i] == 0) continue;
            if (q[d[j][i]] || c[d[j][i]] > 1) {
                q[d[j][i]] = 1;
                if (z[j] == 0) z[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << z[i] << endl;
}
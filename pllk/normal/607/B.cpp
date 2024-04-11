#include <iostream>

using namespace std;

int n;
int c[555];
int d[555][555];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) d[i][i] = 1;
    for (int k = 1; k < n; k++) {
        for (int i = 1; i+k <= n; i++) {
            d[i][i+k] = 999999999;
            int a = i, b = i+k;
            for (int j = a; j < b; j++) {
                d[i][i+k] = min(d[i][i+k],d[a][j]+d[j+1][b]);
            }
            if (c[a] == c[b] && a+1 <= b-1) {
                d[i][i+k] = min(d[i][i+k],d[a+1][b-1]);
            } else if (c[a] == c[b] && a+1 == b) {
                d[i][i+k] = 1;
            }
        }
    }
    cout << d[1][n] << "\n";
}
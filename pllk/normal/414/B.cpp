#include <iostream>

using namespace std;

#define M 1000000007

int n, k;
int d[2020][2020];
int v[2020][2020];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        d[1][i] = 1;
        v[1][i] = 1;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (!v[i][j]) continue;
            for (int k = 1; j*k <= n; k++) {
                v[i+1][j*k] = 1;
                d[i+1][j*k] += d[i][j];
                d[i+1][j*k] %= M;
            }
        }
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += d[k][i];
        s %= M;
    }
    cout << s << endl;
}
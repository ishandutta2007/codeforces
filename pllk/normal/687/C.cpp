#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x[555][555];
int z[555][555];
int n, k;

int main() {
    x[0][0] = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        for (int j = 0; j <= 500 && u+j <= k; j++) {
            if (x[j][j]) {
                z[u+j][u] = 1;
                z[u+j][u+j] = 1;
                for (int h = 0; h <= j && h+u <= k; h++) {
                    if (x[j][h]) z[u+j][h] = 1;
                    if (x[j][h]) z[u+j][h+u] = 1;
                }
            }
        }
        z[u][u] = 1;
        for (int a = 0; a <= k; a++)
        for (int b = 0; b <= a; b++) {
            if (z[a][b]) x[a][b] = 1;
        }
    }
    int c = 0;
    for (int i = 0; i <= k; i++) {
        if (x[k][i]) c++;
    }
    cout << c << "\n";
    for (int i = 0; i <= k; i++) {
        if (x[k][i]) cout << i << " ";
    }
    cout << "\n";
}
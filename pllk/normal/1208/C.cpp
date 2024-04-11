#include <iostream>

using namespace std;

int g[1111][1111];

int main() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 1; i <= n; i += 4) {
        for (int j = 1; j <= n; j++) {
            g[j][i] = c++;
            g[j][i+1] = c++;
            g[j][i+2] = c++;
            g[j][i+3] = c++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}
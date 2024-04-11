#include <iostream>

using namespace std;

int t;
int n, p;

int main() {
    cin >> t;
    for (int x = 0; x < t; x++) {
        cin >> n >> p;
        int v[50][50] = {0};
        for (int i = 3; i <= n; i++) v[1][i] = 1;
        for (int i = 3; i <= n; i++) v[2][i] = 1;
        int c = 2*n+p-2*(n-2);
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (v[i][j]) cout << i << " " << j << endl;
                else if (c > 0) {
                    c--;
                    cout << i << " " << j << endl;
                }
            }
        }
    }
}
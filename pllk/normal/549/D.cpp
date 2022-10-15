#include <iostream>

using namespace std;

int n, m;
string s[111];
int a[111][111];
int c;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            int u;
            if (s[i][j] == 'W') u = 1;
            else u = -1;
            if (u == a[i][j]) continue;
            c++;
            int z = u-a[i][j];
            for (int y = 0; y <= i; y++) {
                for (int x = 0; x <= j; x++) {
                    a[y][x] += z;
                }
            }
        }
    }
    cout << c << "\n";
}
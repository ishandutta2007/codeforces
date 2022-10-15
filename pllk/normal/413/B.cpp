#include <iostream>

using namespace std;

int n, m, k;
int c[101010][20];
int s[101010];
int q[20];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        q[y-1]++;
        s[x-1]++;
    }
    for (int i = 0; i < n; i++) {
        int z = -s[i];
        for (int j = 0; j < m; j++) if (c[i][j]) z += q[j];
        cout << z << " ";
    }
    cout << endl;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, d;
int a[100][100];

int main() {
    cin >> n >> m >> d;
    int v = 0;
    int pi = 10000+1;
    int su = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j]%d != a[0][0]%d) v = 1;
            if (a[i][j] < pi) pi = a[i][j];
            if (a[i][j] > su) su = a[i][j];
        }
    }
    if (v == 1) {
        cout << -1 << endl;
        return 0;
    }
    int tu = -1;
    for (int va = pi; va <= su; va++) {
        int uu = 0;
        if (a[0][0]%d != va%d) continue;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                uu += abs(a[i][j]-va)/d;
            }
        }
        if (tu == -1 || uu < tu) tu = uu;
    }
    cout << tu << endl;
}
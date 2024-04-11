#include <iostream>
#include <vector>

using namespace std;

int r, n;

int m[150];

int d[200][5][5];
int v[200][5][5];

int laske(int k, int a, int b) {
    if (k == 0) return 0;
    if (v[k][a][b]) return d[k][a][b];
    int q[150] = {0}, w;
    for (int i = 0; i < k; i++) {
        if ((i == 0 && a == 2) || (i == k-1 && b == 2)) goto aa;
        w = laske(i, a, 1)^laske(k-i-1, 1, b);
        q[w] = 1;
        aa:
        if ((i == 0 && a == 1) || (i == k-1 && b == 1)) goto bb;
        w = laske(i, a, 2)^laske(k-i-1, 2, b);
        q[w] = 1;
        bb: ;
    }
    int t = 0;
    while (q[t]) t++;
    d[k][a][b] = t;
    v[k][a][b] = 1;
    return t;
}

int main() {
    cin >> r >> n;
    m[0] = 3;
    m[r+1] = 3;
    for (int i = 0; i < n; i++) {
        int y, x;
        cin >> y >> x;
        m[y] += x;
    }
    int s = 0;
    for (int i = 0; i < r+2; i++) {
        if (m[i] == 0) {
            for (int j = i+1; j < r+2; j++) {
                if (m[j] != 0) {
                    s ^= laske(j-i, m[i-1], m[j]);
                    i = j;
                    break;
                }
            }
        }
    }
    if (s == 0) cout << "LOSE\n";
    else cout << "WIN\n";
}
#include<iostream>

using namespace std;
const int N = 1000;
int a[N+10][N+10], out[3][2*N+10], b[N+10], c[N+10];
int ans, mm, nom, help, x, y, n;

void modify(int i, int j) {
    int w;
    for (int t = 1; t <= n; t++) { w = a[t][i]; a[t][i] = a[t][j]; a[t][j] = w; }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        a[x][y] = 1; b[y] += 1;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        mm = -1;
        for (int j = i; j <= n; j++) if (mm < b[j]) { mm = b[j]; nom = j; }
        if (i != nom) {
            ans += 1; out[0][ans] = 2; out[1][ans] = i; out[2][ans] = nom;
            help = b[i]; b[i] = b[nom]; b[nom] = help;
            modify(i, nom);
        }
    }
    for (int i = 1; i <= n; i++) {
        c[i] = 0;
        for (int j = 1; j <= n; j++) if (a[i][j] == 1) c[i] = j;
    }
    for (int i = 1; i <= n; i++) {
        mm = 1e6;
        for (int j = i; j <= n; j++) if (c[j] < mm) { mm = c[j]; nom = j; }
        if (i != nom) {
            ans += 1; out[0][ans] = 1; out[1][ans] = i; out[2][ans] = nom;
            help = c[i]; c[i] = c[nom]; c[nom] = help;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) cout << out[0][i] << " " << out[1][i] << " " << out[2][i] << endl;
    return 0;
}
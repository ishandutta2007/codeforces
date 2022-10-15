#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;

int n;
ll g[555][555];
int y, x;

void lol() {
    cout << "-1\n";
    exit(0);
}

int main() {
    cin >> n;
    if (n == 1) {
        cout << "2\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 0) {y = i; x = j;}
        }
    }
    int u = y-1;
    if (u == 0) u = n;
    ll s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        s1 += g[u][i];
        s2 += g[y][i];
    }
    if (s2 >= s1) lol();
    g[y][x] = s1-s2;
    for (int i = 1; i <= n; i++) {
        ll u = 0;
        for (int j = 1; j <= n; j++) u += g[i][j];
        if (u != s1) lol();
        u = 0;
        for (int j = 1; j <= n; j++) u += g[j][i];
        if (u != s1) lol();
        u = 0;
        for (int j = 1; j <= n; j++) u += g[j][j];
        if (u != s1) lol();
        u = 0;
        for (int j = 1; j <= n; j++) u += g[j][n+1-j];
        if (u != s1) lol();
    }
    cout << s1-s2 << "\n";
}
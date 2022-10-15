#include <iostream>

using namespace std;

int n, m, k;
string s, t;

int z[1111][1111][11][2];
int v[1111][1111][11][2];

int laske(int a, int b, int c, int d) {
    if (a == 0 && b == 0) return 0;
    if (a < 0 || b < 0) return -999999999;
    if (v[a][b][c][d]) return z[a][b][c][d];
    int u = -999999999;
    if (d == 0) {
        if (c > 0) u = max(u,laske(a,b,c-1,1));
        u = max(u,laske(a-1,b,c,0));
        u = max(u,laske(a,b-1,c,0));
    } else {
        u = max(u,laske(a,b,c,0));
        if (a > 0 && b > 0 && s[a] == t[b]) u = max(u,laske(a-1,b-1,c,1)+1);
    }
    z[a][b][c][d] = u;
    v[a][b][c][d] = 1;
    return u;
}

int main() {
    cin >> n >> m >> k;
    cin >> s >> t;
    s = "*"+s;
    t = "*"+t;
    cout << laske(n,m,k,0) << "\n";
}
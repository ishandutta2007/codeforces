#include <iostream>

using namespace std;

#define ll long long

int n, k;
int e[150][150][6];

ll d[150][150];
int v[150][150];

bool ok(int l, int r, int a, int b) {
    if (e[a][b][1]) return false;
    if (e[a][b][3]) return false;
    for (int i = 1; i <= l; i++) {
        if (e[i][a][0]) return false;
        if (e[i][a][3]) return false;
        if (e[i][a][4]) return false;
        if (e[i][b][0]) return false;
        if (e[i][b][3]) return false;
        if (e[i][b][4]) return false;
    }
    for (int i = r; i <= 2*n; i++) {
        if (e[i][a][0]) return false;
        if (e[i][a][3]) return false;
        if (e[i][a][4]) return false;
        if (e[i][b][0]) return false;
        if (e[i][b][3]) return false;
        if (e[i][b][4]) return false;
    }
    return true;
}

ll laske(int a, int b) {
    if (a > b) return 0;
    if (v[a][b]) return d[a][b];
    if (a+1 == b) return ok(a-1,b+1,a,a+1);
    ll s = 0;
    if (ok(a-1,b+1,a,a+1)) s += laske(a+2,b);
    if (ok(a-1,b+1,b-1,b)) s += laske(a,b-2);
    if (ok(a-1,b+1,a,b)) s += laske(a+1,b-1);
    d[a][b] = s;
    v[a][b] = 1;
    return s;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        string x;
        cin >> a >> x >> b;
        if (x == "=") e[a][b][0] = e[b][a][0] = 1;
        if (x == "<") e[a][b][1] = e[b][a][3] = 1;
        if (x == ">") e[b][a][1] = e[a][b][3] = 1;
        if (x == "<=") e[a][b][2] = e[b][a][4] = 1;
        if (x == ">=") e[b][a][2] = e[a][b][4] = 1;
    }
    cout << laske(1, 2*n) << "\n";
}
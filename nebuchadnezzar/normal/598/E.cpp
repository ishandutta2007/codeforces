#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int MAXN = 35, MAXK = 55;

ll d[MAXN][MAXN][MAXK];

ll get(int a, int b, int c) {
    if (d[a][b][c] != -1) {
        return d[a][b][c];
    }
    if (a * b == c || c == 0) {
        return 0;
    }
    if (a * b < c) {
        return 1e18;
    }
    d[a][b][c] = 1e18;
    for (int j = 0; j <= c; ++j) {
        for (int i = 1; i < a; ++i) {
            d[a][b][c] = min(d[a][b][c], (ll) b * b + get(i, b, j) + get(a - i, b, c - j));
        }
        for (int i = 1; i < b; ++i) {
            d[a][b][c] = min(d[a][b][c], (ll) a * a + get(a, i, j) + get(a, b - i, c - j));
        }
    }

    //cerr << a << " " << b << " " << c << " " << d[a][b][c] << endl;

    return d[a][b][c];
}

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    memset(d, -1, sizeof d);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        cout << get(a, b, c) << "\n";
    }

    return 0;
}
#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 2005;

int n, m;
bitset<MAXN> matr[MAXN], inv[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    vector<pii> inp;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        inp.puba({a, b});
        matr[a][b] = 1;
    }

    for (int i = 0; i < n; ++i) {
        inv[i][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int mem = -1;
        for (int j = i; j < n; ++j) {
            if (matr[j][i]) {
                mem = j;
            }
        }
        swap(matr[i], matr[mem]);
        swap(inv[i], inv[mem]);
        for (int j = 0; j < n; ++j) {
            if (j != i && matr[j][i]) {
                matr[j] ^= matr[i];
                inv[j] ^= inv[i];
            }
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cerr << inv[i][j];
        }
        cerr << endl;
    }*/

    for (auto p : inp) {
        cout << (inv[p.ss][p.ff] ? "NO\n" : "YES\n");
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
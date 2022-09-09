#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 505;

int n, m, q;
int field[MAXN][MAXN];                                                                                                 
int ansfor[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
        int x = i;
        int prev = 0;
        ansfor[x] = 0;
        for (int j = 0; j < m; ++j) {
            if (field[x][j]) {
                ansfor[x] = max(ansfor[x], j - prev + 1);
            } else {
                prev = j + 1;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x;--y;
        field[x][y] = 1 - field[x][y];
        int prev = 0;
        ansfor[x] = 0;
        for (int j = 0; j < m; ++j) {
            if (field[x][j]) {
                ansfor[x] = max(ansfor[x], j - prev + 1);
            } else {
                prev = j + 1;
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = max(ans, ansfor[j]);
        }
        cout << ans << endl;
    }

    return 0;
}
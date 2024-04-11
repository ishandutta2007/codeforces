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
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
const int MAXN = 105;

char field[MAXN][MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", field[i]);
    }

    set<pii> szs;
    for (char c : {'R', 'G', 'B'}) {
        int minx = INF, maxx = -INF, miny = INF, maxy = -INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (field[i][j] == c) {
                    minx = min(minx, i);
                    maxx = max(maxx, i);
                    miny = min(miny, j);
                    maxy = max(maxy, j);
                }
            }
        }
        for (int i = minx; i <= maxx; ++i) {
            for (int j = miny; j <= maxy; ++j) {
                if (field[i][j] != c) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
        szs.insert({maxx - minx, maxy - miny});
    }
    
    if (szof(szs) > 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
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

int arr[MAXN][MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }   
    }

    vector<pii> ans;

    if (n > m) {
        for (int j = 0; j < m; ++j) {
            int minv = INF;
            for (int i = 0; i < n; ++i) {
                minv = min(minv, arr[i][j]);
            }
            for (int i = 0; i < n; ++i) {
                arr[i][j] -= minv;
            }
            for (int k = 0; k < minv; ++k) {
                ans.puba({0, j});
            }
        }
        for (int i = 0; i < n; ++i) {
            int minv = INF;
            for (int j = 0; j < m; ++j) {
                minv = min(minv, arr[i][j]);
            }
            for (int j = 0; j < m; ++j) {
                arr[i][j] -= minv;
            }
            for (int k = 0; k < minv; ++k) {
                ans.puba({1, i});
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int minv = INF;
            for (int j = 0; j < m; ++j) {
                minv = min(minv, arr[i][j]);
            }
            for (int j = 0; j < m; ++j) {
                arr[i][j] -= minv;
            }
            for (int k = 0; k < minv; ++k) {
                ans.puba({1, i});
            }
        }
        for (int j = 0; j < m; ++j) {
            int minv = INF;
            for (int i = 0; i < n; ++i) {
                minv = min(minv, arr[i][j]);
            }
            for (int i = 0; i < n; ++i) {
                arr[i][j] -= minv;
            }
            for (int k = 0; k < minv; ++k) {
                ans.puba({0, j});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j]) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << szof(ans) << "\n";

    for (auto p : ans) {
        cout << vector<string>({"col", "row"})[p.ff] << " " << p.ss + 1 << "\n";
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
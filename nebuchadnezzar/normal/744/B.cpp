#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);

int n;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    vector<vector<int>> res;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= 1; ++j) {
            vector<int> reqs;
            for (int k = 0; k < n; ++k) {
                if ((k & (1 << i)) == (1 << i) * j) {
                    reqs.puba(k);
                }
            }
            if (!szof(reqs)) {
                res.puba(vector<int>(n, INF));
                continue;
            }
            cout << szof(reqs) << "\n";
            for (int pos : reqs) {
                cout << pos + 1 << " ";
            }
            cout << endl;
            res.puba(vector<int>(n));
            for (int k = 0; k < n; ++k) {
                scanf("%d", &res.back()[k]);
            }
        }
    }

    cout << "-1\n";

    for (int i = 0; i < n; ++i) {
        int ans = INF;
        for (int j = 0; j < 10; ++j) {
            if ((i & (1 << j))) {
                ans = min(ans, res[j * 2][i]);
            } else {
                ans = min(ans, res[j * 2 + 1][i]);
            }
        }

        cout << ans << " ";
    }
    cout << endl;

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
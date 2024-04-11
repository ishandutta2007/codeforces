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

int n, k;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);

    if (n == 4 && k == 3) {
        cout << "3\n1 2\n2 3\n3 4\n";
        return 0;
    }

    if (k == 1 || k > 3 || n == 2 || n == 3 || n == 4) {
        cout << "-1\n";
        return 0;
    }

    if (k == 3) {
        vector<pii> edges;
        edges.puba({0, 1});
        edges.puba({1, 2});
        for (int i = 3; i < n; ++i) {
            edges.puba({2, i});
        }

        cout << szof(edges) << "\n";
        for (auto e : edges) {
            cout << e.ff + 1 << " " << e.ss + 1 << "\n";
        }
        return 0;
    }

    vector<pii> edges;

    for (int i = 0; i < n - 1; ++i) {
        edges.puba({i, i + 1});
    }

    cout << szof(edges) << "\n";
    for (auto e : edges) {
        cout << e.ff + 1 << " " << e.ss + 1 << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
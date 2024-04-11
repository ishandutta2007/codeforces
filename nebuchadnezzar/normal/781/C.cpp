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
const int MAXN = 2e5 + 5;

int n, m, k;
vector<int> graph[MAXN];
bool used[MAXN];

vector<int> order;

void dfs(int v) {
    used[v] = true;

    order.puba(v);

    for (int to : graph[v]) {
        if (!used[to]) {
            dfs(to);
            order.puba(v);
        }
    }
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    dfs(0);

    int amount = (2 * n + k - 1) / k;

    int c = 0;
    for (int i = 0; i < k; ++i) {
        int cur = min(szof(order) - c, amount);
        if (cur == 0) {
            cout << "1 1\n";
        } else {
            cout << cur << " ";
            for (int j = 0; j < cur; ++j) {
                cout << order[c] + 1 << " ";
                c++;
            }       
            cout << "\n";
        }
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
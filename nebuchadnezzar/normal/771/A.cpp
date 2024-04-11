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

vector<int> graph[MAXN];
bool used[MAXN];
vector<int> now;

int dfs(int v) {
    used[v] = true;
    now.puba(v);
    for (int to : graph[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            now.clear();
            dfs(i);
            for (int v : now) {
                if (szof(graph[v]) != szof(now) - 1) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
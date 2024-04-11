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

int n;
vector<int> graph[MAXN];
int amount;
int color[MAXN];

int dfs(int v, int p, int c1, int c2) {
    int cnt = 0;
    color[v] = c1;
    for (int to : graph[v]) {
        if (to != p) {
            while (cnt == c1 || cnt == c2) {
                ++cnt;
            }
            dfs(to, v, cnt, c1);
            ++cnt;
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }


    amount = 0;
    int mem = -1;
    for (int i = 0; i < n; ++i) {
        if (amount < szof(graph[i]) + 1) {
            amount = szof(graph[i]) + 1;
            mem = i;
        }
    }

    dfs(mem, -1, 0, 0);

    cout << amount << "\n";
    for (int i = 0; i < n; ++i) {
        cout << color[i] + 1 << " ";
    }
    cout << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
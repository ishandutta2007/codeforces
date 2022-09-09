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
const int MAXN = 2007;

int n;
vector<int> graph[MAXN], rgraph[MAXN];
char buf1[50], buf2[50];
bool used[MAXN];

void dfs(int v, vector<int>& arr, vector<int>* g) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, arr, g);
        }
    }
    arr.puba(v);
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    vector<pair<string, string>> inp;

    for (int i = 0; i < n; ++i) {
        scanf("%s%s", buf1, buf2);
        inp.puba({{buf1[0], buf1[1], buf1[2]}, {buf1[0], buf1[1], buf2[0]}});
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (inp[i].ff == inp[j].ff) {
                    graph[i * 2].puba(i * 2 + 1);
                }
                if (inp[i].ff == inp[j].ss) {
                    graph[i * 2].puba(j * 2);
                }
                if (inp[i].ss == inp[j].ff) {
                    graph[i * 2 + 1].puba(j * 2 + 1);
                }
                if (inp[i].ss == inp[j].ss) {
                    graph[i * 2 + 1].puba(j * 2);
                }
            }
        }
    }

    for (int i = 0; i < n * 2; ++i) {
        for (int to : graph[i]) {
            //cerr << i << " -> " << to << endl;
            rgraph[to].puba(i);
        }
    }

    vector<int> order;
    for (int i = 0; i < n * 2; ++i) {
        if (!used[i]) {
            dfs(i, order, graph);
        }
    }

    memset(used, 0, sizeof used);
    reverse(bend(order));

    int c = 0;
    vector<int> color(n * 2);
    for (int v : order) {
        if (!used[v]) {
            vector<int> now;
            dfs(v, now, rgraph);
            for (int u : now) {
                //cerr << u << " " << c << endl;
                color[u] = c;
            }
            ++c;
        }
    }

    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
        if (color[i * 2] == color[i * 2 + 1]) {
            cout << "NO\n";
            return 0;
        }
        if (color[i * 2] < color[i * 2 + 1]) {
            ans[i] = inp[i].ss;
        } else {
            ans[i] = inp[i].ff;
        }
    }

    cout << "YES\n";
    for (auto s : ans) {
        cout << s << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
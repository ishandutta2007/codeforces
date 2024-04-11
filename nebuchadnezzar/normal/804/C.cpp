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
const int MAXN = 3e5 + 5;

vector<int> inp[MAXN];
vector<int> graph[MAXN];
set<int> colors;
int color[MAXN];

int dfs(int v, int p) {
    for (int t : inp[v]) {
        if (color[t] != -1) {
            colors.erase(color[t]);
        }
    }
    for (int t : inp[v]) {
        if (color[t] == -1) {
            color[t] = *colors.begin();
            colors.erase(color[t]);
        }
    }

    for (int t : inp[v]) {
        colors.insert(color[t]);
    }
    
    for (int to : graph[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m;
    scanf("%d%d", &n, &m);

    int c = 0;
    for (int i = 0; i < n; ++i) {
        int s;
        scanf("%d", &s);
        c = max(c, s);

        for (int j = 0; j < s; ++j) {
            int num;
            scanf("%d", &num);
            --num;
            inp[i].puba(num);
        }
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    for (int i = 0; i < c; ++i) {
        colors.insert(i);
    }
    memset(color, -1, sizeof color);

    dfs(0, 0);
    
    c = max(c, 1);
    cout << c << "\n";
    for (int i = 0; i < m; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
        }
        cout << color[i] + 1 << " ";
    }
    cout << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
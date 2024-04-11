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

vector<int> graph[MAXN];
bool used[MAXN];
int ans[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }
    
    vector<int> cur;
    int add = 0;
    vector<int> cnt(n);

    while (add != -1) {
        int next = -1;
        cur.puba(add);
        for (int to : graph[add]) {
            cnt[to]++;
            if (cnt[to] == szof(cur)) {
                next = to;
            }
        }
        add = next;
    }

    vector<bool> marked(n);
    for (int v : cur) {
        marked[v] = 1;
        //cerr << v << " ";
    }
    //cerr << endl;

    map<vector<int>, int> type;
    int c = 0;
    vector<int> res(n, -1);
    for (int v : cur) {
        vector<int> neib;
        for (int to : graph[v]) {
            if (!marked[to]) {
                neib.puba(to);
            }
        }
        sort(bend(neib));
        if (!type.count(neib)) {
            type[neib] = c++;
            if (c > 2) {
                //cout << "NO\n";
                //return 0;
            }      
        }
        
        res[v] = type[neib];
        used[v] = 1;
        ans[v] = res[v];
    }

    //int c = 1e9 / 2;
    for (int w = 0; w < 2; ++w) {
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (res[i] == w) {
                q.push(i);
                used[i] = true;
            }
        }
        while (szof(q)) {
            int v = q.front();
            //cerr << v << " " << ans[v] << endl;
            q.pop();
            for (int to : graph[v]) {
                //cerr << v << " -> " << to << endl;
                if (!used[to]) {
                    used[to] = true;
                    ans[to] = ans[v] + (w == 0 ? -1 : 1);
                    q.push(to);
                }
            }
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        cerr << ans[i] << " ";
    }
    cerr << endl;
    */
    set<pii> edges;
    for (int i = 0; i < n; ++i) {
        for (int to : graph[i]) {
            edges.insert({i, to});
            if (abs(ans[i] - ans[to]) > 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    map<int, vector<int>> by_color;
    for (int i = 0; i < n; ++i) {
        by_color[ans[i]].puba(i);
    }
    
    for (auto& p : by_color) {
        if (by_color.count(p.ff + 1)) {
            for (int v : p.ss) {
                for (int u : by_color[p.ff + 1]) {
                    if (!edges.count({v, u})) {
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
        }
        for (int v : p.ss) {
            for (int u : p.ss) {
                if (v != u) {
                    if (!edges.count({v, u})) {
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
        }
    }

    int val = *min_element(ans, ans + n);

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] - val + 1 << " ";
        assert(1 <= ans[i] - val + 1 && ans[i] - val + 1 <= (int) 1e9);
    }
    cout << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
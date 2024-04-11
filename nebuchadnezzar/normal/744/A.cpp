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
const int MAXN = 1005;

int n, m, k;
vector<int> graph[MAXN];
bool used[MAXN];
vector<int> now;

int dfs(int v) {
    now.puba(v);
    used[v] = true;
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

    scanf("%d%d%d", &n, &m, &k);

    vector<int> is_capital(n);

    for (int i = 0; i < k; ++i) {
        int v;
        scanf("%d", &v);
        --v;
        is_capital[v] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    int ans = 0;
    int best = 0;
    vector<int> no;
    
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            now.clear();
            dfs(i);
            int sum = 0;
            bool flag = false;
            for (int v : now) {
                sum += szof(graph[v]);
                flag |= is_capital[v];
            }
            sum /= 2;
            sum = szof(now) * (szof(now) - 1) / 2 - sum;
            ans += sum;
            //cerr << szof(now) << " " << flag << endl;
            if (flag) {
                best = max(best, szof(now));
            } else {
                no.puba(szof(now));
            }
        }
    }

    for (int num : no) {
        ans += best * num;
        best += num;
    }

    cout << ans << "\n";
     

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
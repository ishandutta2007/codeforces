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
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }


vector<vector<int>> lists;
vector<vector<vector<int>>> inp;
char buf[1000000];
const int MAXN = 1005;
vector<pii> where[MAXN];

vector<int> order;
vector<int> graph[MAXN];

int dfs(int v, int p) {
    order.puba(v);
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
    
    int n;
    scanf("%d", &n);

    vector<int> rest(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        vector<int> arr;
        int now = 0;
        for (int j = 0; buf[j]; ++j) {
            if ('0' <= buf[j] && buf[j] <= '9') {
                now = now * 10 + buf[j] - '0';
            } else {
                if (now) {
                    arr.puba(now);
                }
                now = 0;
            }
        }
        if (now) {
            arr.puba(now);
        }
        inp.puba({});
        lists.puba({});
        int cnt = 0;
        for (int j = 0; j < szof(arr); ++j) {
            lists.back().puba(0);
            inp.back().puba({});
            int m = arr[j];
            ++rest[i];
            ++j;
            for (int q = 0; q < m; ++q, ++j) {
                lists.back().back()++;
                inp.back().back().puba({arr[j] - 1});
                where[arr[j] - 1].puba({i, cnt});
            }
            sort(bend(inp.back().back()));
            --j;
            ++cnt;
        }
        sort(bend(inp.back()));
    }
    
    set<int> have;
    for (int i = 0; i < n; ++i) {
        have.insert(i);
    }

    vector<pii> ans;
    vector<bool> used(n);
    for (int i = 0; i < n - 1; ++i) {
        int mem = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                if (rest[j] == 1) {
                    mem = j;
                    break;
                }
            }
        }
        if (mem == -1) {
            cout << "-1\n";
            return 0;
        }
        used[mem] = 1;
        int to = -1;
        for (auto p : where[mem]) {
            //cerr << p.ff << " " << p.ss << " " << lists[p.ff][p.ss] << endl;
            if (!used[p.ff] && lists[p.ff][p.ss] == 1) {
                to = p.ff;
            }
            --lists[p.ff][p.ss];
            if (!lists[p.ff][p.ss]) {
                --rest[p.ff];
            }
        }
        have.erase(mem);
        if (to == -1) {
            cout << "-1\n";
            return 0;
        }
        ans.puba({mem, to});
    }

    for (pii p : ans) {
        graph[p.ff].puba(p.ss);
        graph[p.ss].puba(p.ff);
    }

    for (int i = 0; i < n; ++i) {
        vector<vector<int>> now;
        for (int to : graph[i]) {
            order.clear();
            dfs(to, i);
            sort(bend(order));
            now.puba(order);
        }
        sort(bend(now));
        if (inp[i] != now) {
            cout << "-1\n";
            return 0;
        }
    }
    
    cout << n - 1 << "\n";
    for (pii p : ans) {
        cout << p.ff + 1 << " " << p.ss + 1 << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
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

int d[MAXN];
vector<int> here[MAXN];
bool really_bad[MAXN];

int dfs(int v, int p) {
    bool flag = false;
    for (int to : graph[v]) {
        if (to != p) {
            dfs(to, v);
            if (d[to] == -1) {
                flag = true;
            }
        }
    }
    if (flag) {
        d[v] = -1;
        really_bad[v] = true;
        return 0;
    }
    set<int> arr;
    for (int to : graph[v]) {
        if (to != p) {
            arr.insert(d[to]);
        }
    }

    for (auto pa : arr) {
        here[v].puba(pa + 1);
    }
    
    if (szof(here[v]) == 0) {
        here[v].puba(0);
        d[v] = 0;
    } else if (szof(here[v]) == 1) {
        d[v] = here[v][0];
    } else {
        d[v] = -1;
    }
    return 0;
}

int ans = INF;

int upd(vector<int>& arr1, vector<int>& arr2) {
    sort(bend(arr1));
    sort(bend(arr2));
    
    vector<int> tmp(szof(arr1) + szof(arr2));
    merge(bend(arr1), bend(arr2), tmp.begin());
    tmp.resize(unique(bend(tmp)) - tmp.begin());
    if (szof(tmp) > 0 && szof(tmp) <= 2) {
        int val = accumulate(bend(tmp), 0);
        //assert(val > 0);
        while (val % 2 == 0) {
            val /= 2;
        }
        //cerr << "upd " << val << endl;
        ans = min(ans, val);
    }
    return 0;
}

int dfs2(int v, int p, vector<int>& val) {
    if (szof(val) >= 2) {
        return 0;
    }
    for (int& num : val) {
        ++num;
    }
    /*
    cerr << "v: " << v << " " << p << endl;
    for (int num : val) {
        cerr << num << " ";
    }
    cerr << endl;
    */
    if (!really_bad[v]) {
        upd(here[v], val);
    }

    set<int> now;
    for (int num : val) {
        now.insert(num);
    }
    vector<set<int>> rl;
    rl.puba(set<int>());
    int mem = 0;
    for (int i = szof(graph[v]) - 1; i >= 0; --i) {
        int to = graph[v][i];
        if (to != p) {
            rl.puba(rl.back());
            if (d[to] == -1) {
                mem = i + 1;
                break;
            }
            //cerr << "add " << v << " " << to << endl;
            for (int num : here[to]) {
                rl.back().insert(num + 1);
                //cerr << "here " << num + 1 << endl;
            }
            if (szof(rl.back()) > 2) {
                mem = i;
                break;
            }
        } else {
            rl.puba(rl.back());
        }
    }
    for (int i = 0; i < szof(graph[v]); ++i) {
        int to = graph[v][i];
        if (to != p) {
            if (szof(now) > 2) {
                break;
            }

            if (i + 1 >= mem) {
                vector<int> tmp;
                for (int num : now) {
                    tmp.puba(num);
                }

                for (int num : rl[szof(graph[v]) - i - 1]) {
                    tmp.puba(num);
                }
                sort(bend(tmp));
                tmp.resize(unique(bend(tmp)) - tmp.begin());
                dfs2(to, v, tmp);
            }
            
            if (d[to] == -1) {
                break;
            }

            for (int num : here[to]) {
                now.insert(num + 1);
            }
        }
    }   
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    dfs(0, -1);

    /*
    for (int i = 0; i < n; ++i) {
        cerr << d[i] << endl;
    }
    */
    vector<int> tmp;

    if (szof(graph[0]) == 1) {
        tmp.puba(-1);
    }

    dfs2(0, -1, tmp);

    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
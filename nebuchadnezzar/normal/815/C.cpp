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
const int MAXN = 1e4 + 10;

int n, b;

vector<int> graph[MAXN];
int arrc[MAXN];
int arrd[MAXN];
vector<ll> d[2][MAXN];

int dfs(int v) {
    auto& with = d[0][v];
    //cerr << v << " " << arrc[v] << " " << arrc[v] - arrd[v] << endl;
    with = {INFL, arrc[v] - arrd[v]};
    auto& without = d[1][v];
    without = {0, arrc[v]};
    for (int to : graph[v]) {
        dfs(to);
        vector<ll> new_with(szof(with) - 1 + szof(d[0][to]) - 1 + 1, INFL);
        for (int i = 0; i < szof(with); ++i) {
            for (int j = 0; j < szof(d[0][to]); ++j) {   
                new_with[i + j] = min(new_with[i + j], with[i] + d[0][to][j]);
            }
        }
        //

        vector<ll> new_without(szof(without) - 1 + szof(d[1][to]) - 1 + 1, INFL);
        
        for (int i = 0; i < szof(without); ++i) {
            for (int j = 0; j < szof(d[1][to]); ++j) {   
                new_without[i + j] = min(new_without[i + j], without[i] + d[1][to][j]);
            }
        }

        /*
        for (int i = 0; i < szof(new_with); ++i) {
            new_with[i] = min(new_with[i], new_without[i]);
        }*/

        with = new_with;
        without = new_without;
    }

    for (int i = 0; i < szof(with); ++i) {
        with[i] = min(with[i], without[i]);
    }
    
    /*
    cerr << v << endl;
    for (ll num : with) {
        cerr << num << " ";
    }
    cerr << endl;
    */
    return 0;
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%d%d", &n, &b);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", arrc + i, arrd + i);
        if (i > 0) {
            int u;
            scanf("%d", &u);
            --u;
            graph[u].puba(i);
        }
    }
    
    dfs(0);
    for (int i = 0; i <= n; ++i) {
        if (d[0][0][i] > b) {
            cout << i - 1 << "\n";
            return 0;
        }
    }


    cout << n << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
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

ll sum[MAXN];
int bymod[10][MAXN];
int n, k;
vector<int> graph[MAXN];

int dfs(int v, int p) {
    for (int to : graph[v]) {
        if (to != p) {
            dfs(to, v);
            sum[v] += sum[to];
            sum[v] += bymod[k - 1][to];
            for (int i = 0; i < k; ++i) {
                bymod[(i + 1) % k][v] += bymod[i][to];
            }
        }
    }
    bymod[0][v] += 1;
    return 0;
}

ll ans[MAXN];

int dfs2(int v, int p, ll sum_up, vector<int> bymod_up) {
    ans[v] = sum[v] + sum_up + accumulate(bend(bymod_up), 0ll);
    for (int i = 1; i < k; ++i) {
        ans[v] += bymod[i][v];
    }
    sum_up += bymod_up.back();
    rotate(bymod_up.begin(), bymod_up.end() - 1, bymod_up.end());
    //bymod_up.insert(bymod_up.begin(), 1);
    bymod_up[0] += 1;
    vector<ll> suff_sum;
    vector<vector<int>> suff_bymod;
    for (int to : graph[v]) {
        if (to != p) {
            suff_sum.puba(sum[to] + bymod[k - 1][to]);
            suff_bymod.puba(vector<int>(k, 0));
            for (int i = 0; i < k; ++i) {
                suff_bymod.back()[(i + 1) % k] += bymod[i][to];
            }
        }
    }
    suff_sum.puba(0);
    suff_bymod.puba(vector<int>(k, 0));
    for (int i = szof(suff_sum) - 2; i >= 0; --i) {
        suff_sum[i] += suff_sum[i + 1];
        for (int j = 0; j < k; ++j) {
            suff_bymod[i][j] += suff_bymod[i + 1][j];
        }
    }

    int c = 0;

    for (int to : graph[v]) {
        if (to != p) {
            vector<int> tmp(k, 0);
            for (int i = 0; i < k; ++i) {
                tmp[i] = bymod_up[i] + suff_bymod[c + 1][i];
            }

            dfs2(to, v, sum_up + suff_sum[c + 1], tmp);

            for (int i = 0; i < k; ++i) {
                bymod_up[(i + 1) % k] += bymod[i][to];
            }

            sum_up += sum[to] + bymod[k - 1][to];

            ++c;
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);

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
        cerr << "i: " << i << ", sum: " << sum[i] << endl;
        for (int j = 0; j < k; ++j) {
            cerr << bymod[j][i] << " ";
        }
        cerr << endl;
    }*/

    dfs2(0, -1, 0, vector<int>(k, 0));

    /*
    for (int i = 0; i < n; ++i) {
        cerr << "ans[" << i << "] = " << ans[i] << endl;
    }*/

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += ans[i];
    }

    cerr << res << endl;
    assert(res % 2 == 0);

    cout << res / 2 << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
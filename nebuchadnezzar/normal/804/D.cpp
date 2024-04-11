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
const int MAXN = 1e5 + 5;

int n, m, q;
bool used[MAXN];
int down[MAXN];
int dist[MAXN];
int color[MAXN];
vector<int> graph[MAXN];

int dfs(int v, int p, int c) {
    color[v] = c;
    used[v] = true;
    for (int to : graph[v]) {
        if (to != p) {
            dfs(to, v, c);
            down[v] = max(down[v], down[to] + 1);
        }
    }
    return 0;
}

int dfs2(int v, int p, int l, vector<int>& arr) {
    dist[v] = max(down[v], l);
    arr.puba(dist[v]);

    vector<int> suff;
    for (int to : graph[v]) {
        if (to != p) {
            suff.puba(down[to] + 1);
        }
    }
    suff.puba(0);
    for (int i = szof(suff) - 2; i >= 0; --i) {
        suff[i] = max(suff[i], suff[i + 1]);
    }

    int c = 0;
    for (int to : graph[v]) {
        if (to != p) {
            dfs2(to, v, max(l, suff[c + 1]) + 1, arr);
            ++c;
            l = max(l, down[to] + 1);
        }
    }
    return 0;
}

vector<vector<ll>> suff;
vector<vector<int>> dists;
map<pii, double> ans;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);
    
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }
    

    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, -1, c);
            vector<int> arr;
            dfs2(i, -1, 0, arr);
            sort(bend(arr));
            dists.puba(arr);
            suff.puba(vector<ll>());
            for (int num : arr) {
                suff.back().puba(num);
            }
            //suff.puba(arr);
            suff.back().puba(0);
            for (int j = szof(suff.back()) - 2; j >= 0; --j) {
                suff.back()[j] += suff.back()[j + 1];
            }
            ++c;
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        cerr << dist[i] << endl;
    }*/
    
    for (int qq = 0; qq < q; ++qq) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        a = color[a];
        b = color[b];

        if (a == b) {
            cout << "-1\n";
            continue;
        }
        if (szof(dists[a]) > szof(dists[b]) || (szof(dists[a]) == szof(dists[b]) && a > b)) {
            swap(a, b);
        }   
        if (ans.count({a, b})) {
            cout << ans[{a, b}] << "\n";
            continue;
        }

        int maxd = max(dists[a].back(), dists[b].back());

        if (szof(dists[a]) * log(szof(dists[b])) < szof(dists[a]) + szof(dists[b])) {
            ll amount = 0;
            ll sum = 0;
            for (int i = 0; i < szof(dists[a]); ++i) {
                int tmp = lower_bound(bend(dists[b]), maxd - dists[a][i] - 1) - dists[b].begin();
                amount += szof(dists[b]) - tmp;
                sum += suff[b][tmp] + (ll) (1 + dists[a][i]) * (szof(dists[b]) - tmp);
            }
            double res = (((ll) szof(dists[a]) * szof(dists[b]) - amount) * maxd + sum) / ((double) szof(dists[a]) * szof(dists[b]));
            ans[{a, b}] = res;
        } else {
            ll amount = 0;
            ll sum = 0;
            int tmp = szof(dists[b]);
            for (int i = 0; i < szof(dists[a]); ++i) {
                //int tmp = lower_bound(bend(dists[b]), maxd - dists[a][i] - 1) - dists[b].begin();
                while (tmp > 0 && dists[a][i] + dists[b][tmp - 1] + 1 >= maxd) {
                    --tmp;
                }
                amount += szof(dists[b]) - tmp;
                sum += suff[b][tmp] + (ll) (1 + dists[a][i]) * (szof(dists[b]) - tmp);
            }
            double res = (((ll) szof(dists[a]) * szof(dists[b]) - amount) * maxd + sum) / ((double) szof(dists[a]) * szof(dists[b]));
            ans[{a, b}] = res;
        }

        cout << ans[{a, b}] << "\n";
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
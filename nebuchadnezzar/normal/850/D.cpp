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
const int MAXN = 65, MAXM = 35, SZ = 2005;

tuple<int, int, int> from[MAXM][MAXN][SZ];
int dist[MAXM][MAXN][SZ];

int calc(int a, int b, int c) {
    return b - a + c;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int m;
    scanf("%d", &m);
    
    vector<int> inp;
    for (int i = 0; i < m; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
    }

    sort(bend(inp));

    tuple<int, int, int> pos = {-1, -1, -1};
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    memset(dist, 127, sizeof dist);
    dist[0][0][0] = 0;
    while (szof(q)) {
        int i, j, k;
        tie(i, j, k) = q.front();
        //cerr << i << " " << j << " " << k << endl;
        q.pop();
        if (i == m) {
            if (k == 0) {
                pos = {i, j, k};
                break;
            }
            continue;
        }
        //if (i < m - 1) {
        int tmp = calc(j, k, inp[i]);
        //cerr << tmp << endl;
        if (tmp >= 0 && dist[i + 1][j + 1][tmp] > dist[i][j][k] + 1) {
            dist[i + 1][j + 1][tmp] = dist[i][j][k] + 1;
            from[i + 1][j + 1][tmp] = {i, j, k};
            q.push({i + 1, j + 1, tmp});
        }
        //}
        //tmp = calc(j, k, inp[i]);
        if (tmp >= 0 && dist[i][j + 1][tmp] > dist[i][j][k] + 1) {
            dist[i][j + 1][tmp] = dist[i][j][k] + 1;
            from[i][j + 1][tmp] = {i, j, k};
            q.push({i, j + 1, tmp});
        }
    }
    
    if (get<0>(pos) == -1) {
        cout << "=(\n";
        return 0;
    }

    vector<int> d;

    while (get<1>(pos) != 0) {
        int i, j, k;
        tie(i, j, k) = pos;
        d.puba(inp[get<0>(from[i][j][k])]);
        pos = from[i][j][k];
    }

    reverse(bend(d));

    vector<vector<bool>> ans(szof(d), vector<bool>(szof(d)));

    for (int i = 0; i < szof(d); ++i) {
        //cerr << i << endl;
        set<pii> now;
        for (int j = 0; j < i; ++j) {
            if (d[j]) {
                now.insert({d[j], j});
            }
        }
        for (int j = 0; j < i; ++j) {
            if (szof(now)) {
                pii tmp = *--now.end();
                if (tmp.ff > d[i]) {
                    ans[tmp.ss][i] = 1;
                    d[tmp.ss]--;
                    now.erase(--now.end());
                } else {
                    --d[i];
                    continue;
                }
            } else {
                --d[i];
            }
        }
        for (int j = 0; j < i; ++j) {
            if (!ans[j][i] && !ans[i][j]) {
                ans[i][j] = 1;
            }
        }
    }

    cout << szof(d) << "\n";

    for (int i = 0; i < szof(d); ++i) {
        for (int j = 0; j < szof(d); ++j) {
            assert(i == j || (ans[i][j] ^ ans[j][i]));
            cout << ans[i][j];
        }
        cout << "\n";
    }
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
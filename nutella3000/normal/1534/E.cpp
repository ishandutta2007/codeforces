#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
const int max_n = 504;

int n, k;
vector<int> gr[max_n];
int lst[max_n], dist[max_n];

void run() {
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, k); ++j) {
            if (j > i || k - j > n - i) continue;
            int to = i + (k - 2 * j);
            gr[i].pb(to);
        }
    }

    deque<int> bfs{n};
    fill(dist, dist + n, inf);
    lst[n] = n;
    while (size(bfs)) {
        int v = bfs.front(); bfs.pop_front();
        for (int to : gr[v]) {
            if (dist[to] == inf) {
                dist[to] = dist[v] + 1;
                lst[to] = v;
                bfs.pb(to);
            }
        }
    }

    if (dist[0] == inf) {
        cout << -1 << endl;
        return;
    }

    vector<int> p;
    int v = 0;
    while (v != n) {
        p.pb(v);
        v = lst[v];
    }
    reverse(all(p));

    vector<bool> used(n, true);
    int sz = n;
    int res = 0;
    for (int ns : p) {
        int del = (k + sz - ns) / 2;
        int ad = k - del;

        cout << "? ";
        for (int i = 0; i < n; ++i) {
            if ((used[i] && del) || (!used[i] && ad)) {
                (used[i] ? --del : --ad);
                used[i] = !used[i];
                cout << i + 1 << " ";
            }
        }
        cout << endl;
        sz = ns;
        cin >> v;
        res ^= v;
    }
    cout << "! " << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}
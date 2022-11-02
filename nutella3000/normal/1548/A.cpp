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

const int max_n = 2e5 + 3;

int cnt = 0;
set<int> gr[max_n];

bool good(int v) {
    return gr[v].empty() || *gr[v].rbegin() < v;
}

void add_edge(int v1, int v2) {
    cnt -= good(v1) + good(v2);
    gr[v1].insert(v2);
    gr[v2].insert(v1);
    cnt += good(v1) + good(v2);
}

void rem_edge(int v1, int v2) {
    cnt -= good(v1) + good(v2);
    gr[v1].erase(v2);
    gr[v2].erase(v1);
    cnt += good(v1) + good(v2);
}

void run() {
    int n, m;
    cin >> n >> m;
    cnt = n;
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2; --v1, --v2;
        add_edge(v1, v2);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t, v1, v2;
        cin >> t;
        if (t == 3) {
            cout << cnt << endl;
        }else {
            cin >> v1 >> v2;
            if (t == 1) add_edge(v1 - 1, v2 - 1);
            else rem_edge(v1 - 1, v2 - 1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}
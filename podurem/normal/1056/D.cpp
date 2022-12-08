#include <bits/stdc++.h>
    #ifdef PoDuReM
        #define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #else
        #define err(...) 42
    #endif

typedef long long ll;

using namespace std;

#define TASK ""
#define multiTest 0

void solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (!strcmp(TASK, "input")) {
            assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
        } else if (strcmp(TASK, "")) {
            assert(freopen(TASK".in", "r", stdin)); assert(freopen(TASK".out", "w", stdout));
        }
    #endif
    int t = 1;
    if (multiTest) {
        cin >> t;
    }
    while (t--) solve();
    return 0;
}

const int dd = (int)1e5 + 7;

vector<int> G[dd];
int cur[dd];

void dfs(int v) {
    if (G[v].size() == 0) {
        cur[v] = 1;
        return;
    }
    for (int to : G[v]) {
        dfs(to);
        cur[v] += cur[to];
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        G[p - 1].push_back(i);
    }
    dfs(0);
    sort(cur, cur + n);
    for (int i = 0; i < n; ++i) {
        cout << cur[i] << " ";
    }
    cout << "\n";
}
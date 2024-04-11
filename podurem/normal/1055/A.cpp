#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
 
using namespace std;

#define TASK ""

int solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (TASK == "input") {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (TASK != "") {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    return solve();
}

const int dd = (int)1e3 + 7;

vector<int> G[dd];
int used[dd];

void dfs(int v) {
    used[v] = 1;
    for (int to : G[v]) if (!used[to]) {
        dfs(to);
    }
}

int solve() {
    int n, s;
    cin >> n >> s;
    --s;
    vector<int> A(n);
    for (int &i : A) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) if (A[i] && A[j]) {
            G[i].push_back(j);
        }
    }
    for (int &i : A) {
        cin >> i;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) if (A[i] && A[j]) {
            G[i].push_back(j);
        }
    }
    dfs(0);
    cout << (used[s] ? "YES\n" : "NO\n");
    return 0;
}
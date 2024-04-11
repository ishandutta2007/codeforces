#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, m;
vector<int> adj[N];
int numSCC;
int cntTarjan;
int low[N], num[N], SCCId[N];
vector<int> st;

void init() {
    numSCC = cntTarjan = 0;
    fill(low + 1, low + n + 1, 0);
    fill(num + 1, num + n + 1, 0);
    fill(SCCId + 1, SCCId + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    st.clear();
}

void tarjan(int u) {
    num[u] = low[u] = ++cntTarjan;
    st.push_back(u);
    for (int v : adj[u]) {
        if (SCCId[v]) continue;
        if (!low[v]) tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
        numSCC++;
        while (1) {
            int v = st.back();
            st.pop_back();
            SCCId[v] = numSCC;
            if (u == v) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        
        init();

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) {
            if (!SCCId[i]) {
                tarjan(i);
            }
        }

        if (numSCC == 1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            vector<int> x, y;
            for (int i = 1; i <= n; i++) {
                if (SCCId[i] == 1) x.push_back(i);
                else y.push_back(i);
            }
            cout << x.size() << ' ' << y.size() << '\n';
            for (int u : x) cout << u << ' ';
                cout << '\n';
            for (int u : y) cout << u << ' ';
                cout << '\n';
        }
    }
    return 0;
}
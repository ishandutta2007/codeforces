#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 123;

int n, m;
vector<int> g[N], rev[N];
bool painted[N];
int cl[N];
vector<int> answer;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rev[v].push_back(u);
    }

    for (int v = 1; v <= n; v++) {
        if (cl[v]) {
            continue;
        }
        cl[v] = v;
        for (int u : g[v]) {
            if (!cl[u]) {
                cl[u] = v;
            }
        }
    }
    for (int v = n; v >= 1; v--) {
        if (cl[v] != v) {
            continue;
        }
        bool ok = false;
        for (int u : rev[v]) {
            ok |= painted[u];
        }
        if (!ok) {
            painted[v] = true;
            answer.push_back(v);
        }
    }

    cout << (int) answer.size() << "\n";
    for (int v : answer) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}
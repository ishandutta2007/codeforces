#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

const int N = 1e5 + 5;
const int K = 500 + 5;

vector<pi> g[N];
int n, m, k, c[K], id[N], turns[K], sp[2][K][K];

bool visited[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);

    vector<bool> v(k + 1);

    visited[s] = true;
    v[id[s]] = true;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (pi &i : g[a]) {
            if (!visited[i.first] and i.second == 0) {
                q.push(i.first);
                visited[i.first] = true;
                v[id[i.first]] = true;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        if (v[i])
            turns[i] += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 500; i++) for (int j = 1; j <= 500; j++)
        sp[0][i][j] = inf;

    cin >> n >> m >> k;
    int ptr = 1;

    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 0; j < c[i]; j++) {
            id[ptr] = i;
            ptr++;
        }
        sp[0][i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);

        int s1 = id[u], s2 = id[v];
        sp[0][s1][s2] = min(sp[0][s1][s2], w);
        sp[0][s2][s1] = min(sp[0][s2][s1], w);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            bfs(i);
    }

    for (int i = 1; i <= k; i++) {
        if (turns[i] > 1) {
            cout << "No\n";
            return 0;
        }
    }

    for (int l = 1; l <= k; l++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                sp[1][i][j] = sp[0][i][j];

                if (sp[0][i][l] != inf and sp[0][l][j] != inf)
                    sp[1][i][j] = min(sp[0][i][j], sp[0][i][l] + sp[0][l][j]);
            }
        }
        memcpy(sp[0], sp[1], sizeof(sp[0]));
    }

    cout << "Yes\n";
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            cout << (sp[0][i][j] != inf ? sp[0][i][j] : -1) << " ";
        }
        cout << "\n";
    }
    return 0;
}
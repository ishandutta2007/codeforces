#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

struct algo {
    int n, m;
    vector<vector<int> > drogi;
    vector<vector<int> > trans;
    vector<bool> visited;
    vector<int> ojciec;
    stack<int> stos;
    vector<int> in;

    algo() {
        cin >> n >> m;

        drogi.resize(2 * n + 10);
        trans.resize(2 * n + 10);
        visited.resize(2 * n + 10);
        ojciec.resize(2 * n + 10);
        in.resize(2 * n + 10);

        for (int a, b, i = 0; i < m; i++) {
            cin >> a >> b;

            drogi[a].push_back(b);
            trans[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            ojciec[i] = i;
            dfs(i);
        }

        while (!stos.empty()) {
            dfs2(stos.top());
            stos.pop();
        }

        for (int i = 1; i <= n; i++) {
            for (int j : drogi[i]) {
                if (f(i) != f(j)) {
                    in[f(j)]++;
                }
            }
        }

        int nr = -1;
        for (int i = 1; i <= n; i++) {
            if (in[f(i)] == 0) nr = f(i);
        }

        if (nr == -1) {
            cout << "No\n";
            return;
        }

        vector<int> j;
        vector<int> p;

        for (int i = 1; i <= n; i++) {
            if (f(i) == nr) {
                p.push_back(i);
            } else {
                j.push_back(i);
            }
        }

        if (p.empty() || j.empty()) {
            cout << "No\n";
            return;
        }

        cout << "Yes\n";
        cout << j.size() << " " << p.size() << "\n";
        for (int i : j) cout << i << " ";
        cout << "\n";
        for (int i : p) cout << i << " ";
        cout << "\n";
    }

    int f(int gdzie) {
        if (gdzie == ojciec[gdzie]) {
            return gdzie;
        }
        return ojciec[gdzie] = f(ojciec[gdzie]);
    }

    void u(int a, int b) {
        ojciec[f(a)] = f(b);
    }

    void dfs(int gdzie) {
        if (visited[gdzie]) {
            return;
        }

        visited[gdzie] = true;
        for (int i : drogi[gdzie]) {
            dfs(i);
        }
        stos.push(gdzie);
    }

    void dfs2(int gdzie) {
        if (!visited[gdzie]) {
            return;
        }

        visited[gdzie] = false;
        for (int i : trans[gdzie]) {
            if (visited[i]) {
                u(gdzie, i);
                dfs2(i);
            }
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        algo p;
    }

    return 0;
}
/*

*/
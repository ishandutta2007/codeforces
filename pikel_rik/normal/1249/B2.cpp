#include <bits/stdc++.h>
using namespace std;

void init(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = 0;
    }
}

int main() {
    int n, q;
    vector<int> p;
    vector<vector<int>> g;
    vector<int> v;
    int j;

    cin >> q;
    vector<vector<int>> ans(q);



    for (int k = 0; k < q; k++) {
        cin >> n;

        p.resize(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        v.resize(n+1);
        init(v);

        g.clear();
        g.resize(n+1);

        for (int i = 1; i <= n; i++) {
            if (v[i] == 0) {
                j = p[i];
                if (j != i)
                    g[i].push_back(j);
                while (j != i) {
                    v[j] = 1;
                    if (p[j] != i)
                        g[i].push_back(p[j]);
                    j = p[j];
                }
            }
        }

        ans[k].resize(n+1);

        for (int i = 1; i <= n; i++) {
            if (v[i] == 0) {
                ans[k][i] = g[i].size() + 1;
                for (int j = 0; j < g[i].size(); j++)
                    ans[k][g[i][j]] = ans[k][i];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        for (int j = 1; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> G(n);
    set<pair<int, int>> roads;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        roads.insert({ u, v });
        roads.insert({ v, u });
        G[u].push_back(v);
        G[v].push_back(u);
    }
    --s, --t;
    queue<int> ques, quet;
    vector<bool> useds(n), usedt(n);
    vector<int> depths(n), deptht(n);
    useds[s] = true;
    usedt[t] = true;
    ques.push(s);
    while (ques.size() > 0) {
        int from = ques.front();
        ques.pop();
        for (auto i : G[from])
            if (!useds[i]) {
                depths[i] = depths[from] + 1;
                ques.push(i);
                useds[i] = true;
            }
    }

    quet.push(t);
    while (quet.size() > 0) {
        int from = quet.front();
        quet.pop();
        for (auto i : G[from])
            if (!usedt[i]) {
                deptht[i] = deptht[from] + 1;
                quet.push(i);
                usedt[i] = true;
            }
    }

    int len = depths[t], ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (!roads.count({ i, j })) {
                if (depths[i] + deptht[j] + 1 >= len && deptht[i] + depths[j] + 1 >= len)
                    ++ans;
            }
    cout << ans;
    return 0;
}
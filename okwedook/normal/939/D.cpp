#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G(26, vector<int>(26));
vector<bool> used(26, 0);
vector<pair<int, int>> ans;

void dfs(int v, int p) {
    used[v] = true;
    if (p != 200) ans.push_back({p, v});
    for (auto i : G[v])
        if (!used[i])
            dfs(i, v);
}

int main() {
    int n;
    cin >> n;
    vector<bool> arr(200);
    string s, t;
    cin >> s >> t;
    for (auto &i : s) i -= 97;
    for (auto &i : t) i -= 97;
    for (int i = 0; i < n; ++i)
        if (s[i] != t[i]) {
            G[s[i]].push_back(t[i]);
            G[t[i]].push_back(s[i]);
        }
    int count = 0;
    for (int i = 0; i < 26; ++i)
        if (!used[i])
            dfs(i, 200);
    cout << ans.size() << '\n';
    for (auto i : ans) cout << (char)(i.first + 97) << ' ' << (char)(i.second + 97) << '\n';
    //system("pause");
    return 0;
}
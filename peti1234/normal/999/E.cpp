#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int n, m, p, ans, ki[c], el[c];
vector<int> sz[c], s[c], k;
bool v[c], v2[c];
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    k.push_back(a);
}
void dfs2(int a, int b) {
    ki[a]=b;
    v2[a]=true;
    for (int x:s[a]) {
        if (!v2[x]) {
            dfs2(x, b);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i=1; i<=m; i++) {
        int a, b;cin >> a >> b;
        sz[a].push_back(b), s[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
    reverse(k.begin(), k.end());
    for (int i:k) {
        if (!v2[i]) {
            dfs2(i, i);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j:sz[i]) {
            if (ki[i]!=ki[j]) el[ki[j]]++;
        }
    }
    for (int i=1; i<=n; i++) {
        if (ki[i]==i && ki[p]!=i && el[i]==0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
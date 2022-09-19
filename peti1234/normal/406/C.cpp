#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, f[c], el[c], p=1;
bool v[c];
vector<int> sz[c];
bool dfs(int a) {
    v[a]=true, el[a]=p, p++;
    vector<int> s;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (x!=f[a] && v[x] && el[a]<el[x]) s.push_back(x);
        if (!v[x]) {
            f[x]=a;
            if (!dfs(x)) s.push_back(x);
        }
    }
    int si=s.size();
    for (int i=1; i<si; i+=2) cout << s[i-1] << " " << a << " " << s[i] << "\n";
    if (si%2) cout << s[si-1] << " " << a << " " << f[a] << "\n";
    return si%2;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    if (m%2) cout << "No solution\n";
    else dfs(1);
    return 0;
}
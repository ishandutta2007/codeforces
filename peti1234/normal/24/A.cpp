#include <bits/stdc++.h>

using namespace std;
const int c=102;
int n, sum, ert;
vector<int> sz[c], s[c];
bool v[c];
void dfs(int a, int el) {
    if (v[a]) {
        return;
    }
    v[a]=true;
    int x=sz[a][0], y=sz[a][1];
    if (x!=el) {
        ert+=s[a][0];
        dfs(x, a);
    } else {
        ert+=s[a][1];
        dfs(y, a);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a);
        s[a].push_back(0), s[b].push_back(c);
        sum+=c;
    }
    dfs(1, sz[1][0]);
    cout << min(ert, sum-ert) << "\n";
    return 0;
}
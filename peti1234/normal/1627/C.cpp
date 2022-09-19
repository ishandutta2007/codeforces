#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, ans[c];
bool v[c];
vector<pair<int, int> > sz[c];
void dfs(int a, int b) {
    v[a]=true;
    for (auto p:sz[a]) {
        int x=p.first, y=p.second;
        if (!v[x]) {
            ans[y]=b;
            dfs(x, 5-b);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back({b, i});
            sz[b].push_back({a, i});
        }
        int ert=0, pos=0;
        for (int i=1; i<=n; i++) {
            int si=sz[i].size();
            ert=max(ert, si);
            if (si==1) pos=i;
        }
        if (ert>2) {
            cout << -1 << "\n";
        } else {
            dfs(pos, 2);
            for (int i=1; i<n; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }

        for (int i=1; i<=n; i++) {
            ans[i]=0, v[i]=0;
            sz[i].clear();
        }
    }
    return 0;
}
/*
1
4
1 3
4 3
2 1
*/
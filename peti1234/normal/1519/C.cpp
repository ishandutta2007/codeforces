#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, u[c], p[c], ans[c];
vector<long long> sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            ans[i]=0;
            sz[i].clear();
        }
        for (int i=1; i<=n; i++) {
            cin >> u[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> p[i];
            sz[u[i]].push_back(p[i]);
        }
        for (int i=1; i<=n; i++) {
            sort(sz[i].rbegin(), sz[i].rend());
            int si=sz[i].size();
            for (int j=1; j<si; j++) {
                sz[i][j]+=sz[i][j-1];
            }
            for (int k=1; k<=si; k++) {
                ans[k]+=sz[i][si-si%k-1];
            }
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> sz[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        sz[i].push_back(i);
        int si=sz[i].size();
        cout << 2*si-1 << "\n";
        for (int x:sz[i]) {
            cout << i << " " << x*n+i << "\n";
            if (i!=x) cout << i << " " << i*n+x << "\n";
        }
    }
    return 0;
}
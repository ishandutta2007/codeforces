#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, q, cnt, be[c], inv[c], si[c];
vector<int> sz[c];
void dfs(int a) {
    be[a]=++cnt;
    inv[cnt]=a;
    si[a]=1;
    for (auto x:sz[a]) {
        dfs(x);
        si[a]+=si[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=2; i<=n; i++) {
        int x;
        cin >> x;
        sz[x].push_back(i);
    }
    dfs(1);
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (si[a]<b) {
            cout << -1 << "\n";
        } else {
            cout << inv[be[a]+b-1] << "\n";
        }
    }
    return 0;
}
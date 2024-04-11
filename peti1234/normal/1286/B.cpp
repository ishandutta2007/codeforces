#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, rf[c], ert[c], ans[c], k, cnt;
vector<int> sz[c];
void p(int a) {
    rf[a]=1;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        p(x), rf[a]+=rf[x];
    }
}
bool dfs(int a) {
    if (rf[a]-1==ert[a]) {ans[a]=cnt, rf[a]--, cnt--; return true;}
    for (int i=0; i<sz[a].size(); i++) if (dfs(sz[a][i])) { rf[a]--; return true;}
    return false;
}
int main()
{
    cin >> n, cnt=n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x >> ert[i];
        sz[x].push_back(i);
    }
    p(0);
    for (int i=1; i<=n; i++) if (ert[i]>=rf[i]) {
        cout << "NO\n";
        return 0;
    }
    for (int i=1; i<=n; i++) dfs(0);
    cout << "YES\n";
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}
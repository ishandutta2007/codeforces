#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, sum, ans, ert[c], szint[c], rf[c];
vector<int> sz[c];
bool v[c], v2[c];
void dfs(int a) {
    v[a]=true;
    sum+=szint[a]*ert[a];
    rf[a]=ert[a];
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
            rf[a]+=rf[x];
        }
    }
}
void dfs2(int a, long long p) {
    v2[a]=true;
    ans=max(ans, p);
    for (auto x:sz[a]) {
        if (!v2[x]) {
            dfs2(x, p+rf[1]-2*rf[x]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    dfs2(1, sum);
    cout << ans << "\n";
    return 0;
}
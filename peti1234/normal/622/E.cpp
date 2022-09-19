#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, ans;
vector<int> sz[c], l;
bool v[c];
void dfs(int a, int p) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x, p+1);
        }
    }
    if (sz[a].size()==1) {
        l.push_back(p);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    v[1]=true;
    for (auto x:sz[1]) {
        dfs(x, 1);
        sort(l.begin(), l.end());
        int ert=0;
        for (auto x:l) {
            ert=max(ert+1, x);
        }
        ans=max(ans, ert);
        l.clear();
    }
    cout << ans << "\n";
    return 0;
}
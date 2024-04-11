#include <bits/stdc++.h>

using namespace std;
const int c=50005;
int n, r, s, ans[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            ans[x]=a;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> r;
    for (int i=1; i<=n; i++) {
        if (i!=s) {
            int x;
            cin >> x;
            sz[i].push_back(x);
            sz[x].push_back(i);
        }
    }
    dfs(r);
    for (int i=1; i<=n; i++) {
        if (i!=r) {
            cout << ans[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}
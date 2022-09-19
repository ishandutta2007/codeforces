#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, w, ans[c], lg[c];
vector<int> sz[c], ert[20];
bool v[c];
int dfs(int a) {
    v[a]=true;
    bool pos[20];
    for (int i=0; i<20; i++) pos[i]=1;
    for (auto x:sz[a]) {
        if (!v[x]) {
            pos[dfs(x)]=0;
        }
    }
    for (int i=19; i>=0; i--) {
        if (ert[i].size()>0 && pos[i]) {
            ans[a]=ert[i].back();
            ert[i].pop_back();
            return i;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) lg[i]=lg[i/2]+1;
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            ert[lg[i]].push_back(i);
        }
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";

        for (int i=1; i<=n; i++) {
            sz[i].clear();
            v[i]=0, ans[i]=0;
        }
    }
    return 0;
}
/*
1
3
1 2
1 3
*/
#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, ut;
vector<int> sz[c], rev[c];
vector<pair<int, int> > s[2];
bool v[c], v2[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    ut=a;
}
void dfs2(int a) {
    v2[a]=true;
    for (auto x:rev[a]) {
        if (!v2[x]) {
            dfs2(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int j=0; j<2; j++) {
            for (int i=1; i<=n; i++) {
                int x;
                cin >> x;
                s[j].push_back({x, i});
            }
            sort(s[j].begin(), s[j].end());
            for (int i=1; i<n; i++) {
                sz[s[j][i].second].push_back(s[j][i-1].second);
                rev[s[j][i-1].second].push_back(s[j][i].second);
            }
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                dfs(i);
            }
        }
        dfs2(ut);

        for (int i=1; i<=n; i++) {
            cout << v2[i];
        }
        cout << "\n";

        for (int i=1; i<=n; i++) {
            sz[i].clear(), rev[i].clear(), v[i]=0, v2[i]=0;
        }
        s[0].clear(), s[1].clear();

    }
    return 0;
}
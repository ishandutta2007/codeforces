#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, q, ans[c][c];
vector<pair<int, int> > fr;
bool t[c][c], v[c][c];
void dfs(int a, int b) {
    v[a][b]=true;
    fr.push_back({a, b});
    int aa, bb;

    aa=a-1, bb=b;
    if (!v[aa][bb]) {
        if (!t[aa][bb]) {
            dfs(aa, bb);
            ans[a][b]+=ans[aa][bb];
        } else {
            ans[a][b]++;
        }
    }
    aa=a+1;
    if (!v[aa][bb]) {
        if (!t[aa][bb]) {
            dfs(aa, bb);
            ans[a][b]+=ans[aa][bb];
        } else {
            ans[a][b]++;
        }
    }
    aa=a, bb=b-1;
    if (!v[aa][bb]) {
        if (!t[aa][bb]) {
            dfs(aa, bb);
            ans[a][b]+=ans[aa][bb];
        } else {
            ans[a][b]++;
        }
    }
    bb=b+1;
    if (!v[aa][bb]) {
        if (!t[aa][bb]) {
            dfs(aa, bb);
            ans[a][b]+=ans[aa][bb];
        } else {
            ans[a][b]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            t[i][j]=(c=='*');
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!v[i][j] && !t[i][j]) {
                dfs(i, j);
                for (auto x:fr) {
                    ans[x.first][x.second]=ans[i][j];
                }
                fr.clear();
            }
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << "\n";
    }
    return 0;
}
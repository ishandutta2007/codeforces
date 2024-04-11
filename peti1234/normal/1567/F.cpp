#include <bits/stdc++.h>

using namespace std;
const int c=505, c2=c*c;
int n, m, ans[c2];
bool t[c][c], v[c2];
vector<int> sz[c2], sz2[c2];


int valt(int a, int b) {
    return (a-1)*m+b;
}
void add(int a, int b) {
    sz2[a].push_back(b), sz2[b].push_back(a);
}

void dfs(int a) {
    v[a]=1;
    for (auto x:sz2[a]) {
        if (!v[x]) {
            ans[x]=5-ans[a];
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            t[i][j]=(c=='X');
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (t[i][j]) {
                int s=valt(i, j);
                if (!t[i-1][j]) sz[s].push_back(valt(i-1, j));
                if (!t[i+1][j]) sz[s].push_back(valt(i+1, j));
                if (!t[i][j-1]) sz[s].push_back(valt(i, j-1));
                if (!t[i][j+1]) sz[s].push_back(valt(i, j+1));
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (t[i][j]) {
                int s=valt(i, j);
                int si=sz[s].size();
                if (si%2) {
                    cout << "NO\n";
                    return 0;
                }
                sort(sz[s].begin(), sz[s].end());
                for (int i=0; i<si; i+=2) {
                    add(sz[s][i], sz[s][i+1]);
                }
                ans[s]=si/2*5;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!t[i][j]) {
                int s=valt(i, j);
                if (!v[s]) {
                    ans[s]=1;
                    dfs(s);
                }
            }
        }
    }

    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << ans[valt(i, j)] << " ";
        }
        cout << "\n";
    }

    return 0;
}
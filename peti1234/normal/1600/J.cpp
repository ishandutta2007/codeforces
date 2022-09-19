#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int si[c][c];
pair<int, int> ki[c][c];
vector<int> ans;
pair<int, int> holvan(int a, int b) {
    pair<int, int> p={0, 0};
    if (ki[a][b]==p) {
        return {a, b};
    }
    return ki[a][b]=holvan(ki[a][b].first, ki[a][b].second);
}
void unio(int a, int b, int c, int d) {
    //cout << "unio " << a << " " << b << " " << c << " " << d << "\n";
    pair<int, int> x=holvan(a, b), y=holvan(c, d);
    if (x!=y) {
        si[y.first][y.second]+=si[x.first][x.second];
        si[x.first][x.second]=0;
        ki[x.first][x.second]=y;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            si[i][j]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            if ((x & 8)==0) unio(i, j, i-1, j);
            if ((x & 4)==0) unio(i, j, i, j+1);
            if ((x & 2)==0) unio(i, j, i+1, j);
            if ((x & 1)==0) unio(i, j, i, j-1);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (si[i][j]) {
                ans.push_back(si[i][j]);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (auto x:ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
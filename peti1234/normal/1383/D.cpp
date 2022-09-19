#include <bits/stdc++.h>

using namespace std;
const int c=252;
vector<pair<int, int> > h;
int n, m, t[c][c], sol[c][c], sm[c], om[c], x, y, id;
bool ms[c*c], mo[c*c];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> t[i][j], sm[i]=max(sm[i], t[i][j]), om[j]=max(om[j], t[i][j]);
    for (int i=1; i<=n; i++) ms[sm[i]]=1;
    for (int i=1; i<=m; i++) mo[om[i]]=1;
    for (int i=n*m; i>=1; i--) {
        if (ms[i]) x++;
        if (mo[i]) y++;
        if (ms[i] || mo[i]) {
            sol[x][y]=i;
            for (int i=y-1; i>=1; i--) h.push_back({x, i});
            for (int i=x-1; i>=1; i--) h.push_back({i, y});
        } else {
            while(sol[h[id].first][h[id].second]) id++;
            sol[h[id].first][h[id].second]=i;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) cout << sol[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
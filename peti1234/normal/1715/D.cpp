#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, m, ans[c][30];
vector<pair<int, int> > sz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back({b, c});
        sz[b].push_back({a, c});
        for (int j=0; j<30; j++) {
            if ((c & (1<<j))==0) {
                ans[a][j]=-1;
                ans[b][j]=-1;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<30; j++) {
            ans[i][j]=-1;
            for (auto p:sz[i]) {
                int x=p.first, ert=(p.second & (1<<j));
                if (ert && ans[x][j]==-1) {
                    ans[i][j]=1;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        int sum=0;
        for (int j=0; j<30; j++) {
            if (ans[i][j]==1) {
                sum+=(1<<j);
            }
        }
        cout << sum << " ";
    }
    cout << "\n";
    return 0;
}
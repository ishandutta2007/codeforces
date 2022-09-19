#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> >kul[101];
int t[101];
int sum[101];
int n, m, x=1, y;
int main()
{
    cin >> n >> m;
    for (int k=1; k<=m; k++) {
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum[i]+=t[i];
            if (i==n) {
                for (int j=1; j<n; j++) {
                    kul[j].push_back({t[j]-t[n], k});
                }
            }
        }
    }
    for (int i=1; i<n; i++) {
        sort(kul[i].begin(), kul[i].end());
    }
    y=m;
    for (int i=1; i<n; i++) {
        int ossz=0;
        for (int j=0; j<m; j++) {
            if (sum[n]+ossz<=sum[i]) {
                if (j<y) {
                    y=j, x=i;
                }
            }
            ossz+=kul[i][j].first;
        }
    }
    cout << y << "\n";
    for (int i=0; i<y; i++) {

        cout << kul[x][i].second << " ";
    }
    return 0;
}
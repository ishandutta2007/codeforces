#include <bits/stdc++.h>

using namespace std;
int w, n, m;
vector<vector<int>> v, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int tc=1; tc<=w; tc++) {
        cin >> n >> m;
        v.resize(n+1), maxi.resize(n+1);
        for (int i=1; i<=n; i++) v[i].resize(m+1), maxi[i].resize(m+1);
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            v[i][j]=(c=='1');
        }

        int s[2]={0, 0};
        for (int j=1; j<=m; j++) {
            for (int i=1; i<=n; i++) {
                if (j>1) {
                    if (i>1) maxi[i][j]=max(maxi[i][j], maxi[i-1][j-1]);
                    if (i<n) maxi[i][j]=max(maxi[i][j], maxi[i+1][j-1]);
                }
                int ert=(j>2 ? maxi[i][j-2] : 0);
                maxi[i][j]=max(maxi[i][j], ert+v[i][j]);
                int p=(i+j)%2;
                s[p]=max(s[p], maxi[i][j]);
            }
        }
        cout << s[0]+s[1] << "\n";
        v.clear(), maxi.clear();
    }
    return 0;
}
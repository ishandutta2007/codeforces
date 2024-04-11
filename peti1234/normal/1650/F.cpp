#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=105;
int w, n, m, t[c], ert[c][k], sok=1e9+1;
vector<int> sz[c][k], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=100; j++) {
                ert[i][j]=sok;
                sz[i][j].clear();
            }
        }

        for (int i=1; i<=m; i++) {
            int id, h, db;
            cin >> id >> h >> db;
            for (int j=99; j>=0; j--) {
                int kov=min(100, j+db);
                if (ert[id][j]<sok && ert[id][j]+h<ert[id][kov]) {
                    ert[id][kov]=ert[id][j]+h;
                    sz[id][kov]=sz[id][j];
                    sz[id][kov].push_back(i);
                }
            }
        }
        int val=0, baj=0;
        for (int i=1; i<=n; i++) {
            val+=ert[i][100];
            if (val>t[i]) {
                baj=1;
                break;
            }
            for (auto x:sz[i][100]) {
                ans.push_back(x);
            }
        }
        //cout << "valasz............................ ";
        if (baj) {
            cout << -1 << "\n";
        } else {
            cout << ans.size() << "\n";
            for (auto x:ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
        ans.clear();
    }
    return 0;
}
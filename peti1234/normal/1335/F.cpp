#include <bits/stdc++.h>

using namespace std;
int w, n, m, x, y, db, fdb;
vector<pair<int, int> > sz[1000002], ch[1000002];
vector<bool> v[1000002], h[1000002];
char c;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        db=0, fdb=0;
        for (int i=1; i<=n; i++) {
            v[i].clear(), h[i].clear(), sz[i].clear(), ch[i].clear();
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<m; j++) {
                v[i].push_back(0);
                cin >> c;
                if (c=='0') h[i].push_back(0);
                else h[i].push_back(1);
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<m; j++) {
                cin >> c, x=i, y=j;
                if (c=='U') x--;
                if (c=='D') x++;
                if (c=='L') y--;
                if (c=='R') y++;
                sz[i].push_back({x, y}), ch[i].push_back({0, 0});
            }
        }
        for (int k=1; k<=21; k++) {
            for (int i=1; i<=n; i++) {
                for (int j=0; j<m; j++) {
                    if (k%2) {
                        int fi=sz[i][j].first, se=sz[i][j].second, x=sz[fi][se].first, y=sz[fi][se].second;
                        ch[i][j]={x, y};
                    } else {
                        int fi=ch[i][j].first, se=ch[i][j].second, x=ch[fi][se].first, y=ch[fi][se].second;
                        sz[i][j]={x, y};
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<m; j++) {
                int x=ch[i][j].first, y=ch[i][j].second;
                if (!h[i][j] && !v[x][y]) v[x][y]=1, fdb++;
                //cout << i << " " << j << " " << x << " " << y << endl;
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<m; j++) {
                int x=ch[i][j].first, y=ch[i][j].second;
                if (!v[x][y]) v[x][y]=1, db++;
            }
        }
        cout << db+fdb << " " << fdb << "\n";
    }
    return 0;
}
// Ezt j lenne megcsinlni, hogy teljes ksz legyen a verseny.
/*
1
3 3
000
000
000
RRD
RLD
ULL
*/
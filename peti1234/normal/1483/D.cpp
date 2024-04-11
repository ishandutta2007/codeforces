#include <bits/stdc++.h>

using namespace std;
const int cc=602;
int n, m, q;
long long dist[cc][cc], cel[cc][cc],  sok=1e15, ans;
vector<pair<pair<int, int>, long long> > el;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j) {
                dist[i][j]=sok;
            }
        }
    }
    for (int i=1; i<=m; i++) {
        long long a, b, c; cin >> a >> b >> c;
        el.push_back({{a, b}, c});
        dist[a][b]=c, dist[b][a]=c;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        for (int koz=1; koz<=n; koz++) {
            cel[a][koz]=max(cel[a][koz], c-dist[koz][b]);
            cel[b][koz]=max(cel[b][koz], c-dist[a][koz]);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cel[i][j]=max(cel[i][j], cel[j][i]);
        }
    }
    for (auto i:el) {
        int a=i.first.first, b=i.first.second;
        long long tav=i.second;
        bool jo=0;
        for (int veg=1; veg<=n; veg++) {
            if (tav+dist[b][veg]<=cel[a][veg]) {
                jo=1;
            }
        }
        ans+=jo;
    }
    cout << ans << "\n";

    return 0;
}
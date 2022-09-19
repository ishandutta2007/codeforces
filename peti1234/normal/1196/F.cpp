#include <bits/stdc++.h>

using namespace std;
const int c=805;
int n, m, k, cnt;
long long tav[c][c], sok=1e15;
vector<pair<int, pair<int, int> > > el;
vector<long long> dist;
map<int, int> id;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        el.push_back({c, {a, b}});
    }
    sort(el.begin(), el.end());
    for (int i=0; i<min(m, k); i++) {
        int c=el[i].first, a=el[i].second.first, b=el[i].second.second;
        if (!id[a]) id[a]=++cnt;
        if (!id[b]) id[b]=++cnt;
        a=id[a], b=id[b];
        //cout << "el " << a << " " << b << "\n";
        tav[a][b]=c, tav[b][a]=c;
    }
    for (int i=1; i<=cnt; i++) {
        for (int j=1; j<=cnt; j++) {
            if (i!=j && !tav[i][j]) {
                tav[i][j]=sok;
            }
        }
    }
    for (int k=1; k<=cnt; k++) {
        for (int i=1; i<=cnt; i++) {
            for (int j=1; j<=cnt; j++) {
                tav[i][j]=min(tav[i][j], tav[i][k]+tav[k][j]);
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        for (int j=i+1; j<=cnt; j++) {
            //cout << i << " " << j << " " << tav[i][j] << "\n";
            dist.push_back(tav[i][j]);
        }
    }
    sort(dist.begin(), dist.end());
    cout << dist[k-1] << "\n";
    return 0;
}
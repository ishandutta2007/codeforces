#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, w;
long long dist[c], d[c], suly[c], sok=1e16;
vector<pair<int, int> > sz[c];
bool v[c], jo;
priority_queue<pair<long long, int> > q;
queue<int> sq[c];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> w;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        suly[i]=c;
        sz[a].push_back({b, i});
    }
    for (int i=2; i<=n; i++) {
        dist[i]=sok;
    }
    q.push({0, 1});
    while (q.size()>0) {
        int id=q.top().second;
        q.pop();
        if (!v[id]) {
            v[id]=1;
            for (auto x:sz[id]) {
                int fi=x.first;
                long long uj=dist[id]+suly[x.second];
                if (uj<dist[fi]) {
                    dist[fi]=uj;
                    q.push({-uj, fi});
                }
            }
        }
    }

    for (int i=1; i<=w; i++) {
        int f;
        cin >> f;
        if (f==1) {
            int cel;
            cin >> cel;
            cout << (dist[cel]==sok ? -1 : dist[cel]) << "\n";
        } else {
            int x;
            cin >> x;
            for (int i=1; i<=x; i++) {
                int y;
                cin >> y;
                suly[y]++;
            }
            for (int i=1; i<=n; i++) {
                d[i]=min(sok, dist[i]+n);
                v[i]=0;
            }
            d[1]=0;
            sq[0].push(1);
            for (int dif=0; dif<n; dif++) {
                while (sq[dif].size()) {
                    int id=sq[dif].front();
                    sq[dif].pop();
                    if (!v[id]) {
                        v[id]=1;
                        for (auto x:sz[id]) {
                            int kov=x.first;
                            long long tav=d[id]+suly[x.second];
                            if (tav<d[kov]) {
                                d[kov]=tav;
                                sq[d[kov]-dist[kov]].push(kov);
                            }
                        }
                    }
                }
            }
            for (int i=1; i<=n; i++) {
                dist[i]=d[i];
            }

        }
    }
    return 0;
}
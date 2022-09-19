#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long w, n, m, k, ar[c], kezd[c], veg[c], szint[c], val[c], sok=1e18;
vector<int> sz[c];
vector<pair<long long, long long> > vis[c], uj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        for (int i=1; i<=n; i++) {
            cin >> ar[i];
        }
        for (int i=1; i<=k; i++) {
            int a, b, c, d, e;
            cin >> a >> kezd[i] >> szint[i] >> veg[i] >> val[i];
            sz[a].push_back(i);
        }
        k++;
        sz[n].push_back(k);
        kezd[k]=m, szint[k]=n+1;


        vis[1].push_back({1, 0});
        for (int i=1; i<=n; i++) {
            sort(vis[i].begin(), vis[i].end());
            for (auto x:vis[i]) {
                while (uj.size()>0 && x.second>=uj.back().second+(x.first-uj.back().first)*ar[i]) {
                    uj.pop_back();
                }
                if (uj.size()==0 || x.second+(x.first-uj.back().first)*ar[i]>uj.back().second) {
                    uj.push_back(x);
                }
            }
            int si=uj.size();
            if (si==0) continue;
            for (auto p:sz[i]) {
                long long pos=kezd[p];
                int lo=-1, hi=si, mid;
                while (hi-lo>1) {
                    mid=(hi+lo)/2;
                    if (uj[mid].first>=pos) hi=mid;
                    else lo=mid;
                }

                long long ert=-sok;
                if (lo>=0) ert=max(ert, uj[lo].second-ar[i]*(pos-uj[lo].first));
                if (hi<si) ert=max(ert, uj[hi].second-ar[i]*(uj[hi].first-pos));

                vis[szint[p]].push_back({veg[p], ert+val[p]});
            }
            uj.clear();
        }

        if (vis[n+1].size()>0) {
            cout << -vis[n+1][0].second << "\n";
        } else {
            cout << "NO ESCAPE\n";
        }


        for (int i=0; i<=max({n, m, k})+3; i++) {
            ar[i]=0, kezd[i]=0, veg[i]=0, szint[i]=0, val[i]=0;
            sz[i].clear(), vis[i].clear();
        }
    }
    return 0;
}
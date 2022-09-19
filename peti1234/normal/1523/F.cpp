#include <bits/stdc++.h>

using namespace std;
const int c=(1<<14), s=120, sok=1e9+5;
int n, n2, m, nm, x[s], y[s], t[s], dist[c][s], ans;
int dpb[c][s], dpcs[c][s], pos[c];
// dpb : c mask, s kuldetes kesz, dpb[c][s] minimalis ido, ami alatt meg lehet csinalni
// dpcs : c mask, s. kuldetest teljesitettem, (t[s] ido) osszesen dpcs[c][s] kuldetes lett meg
// pos c maskban maximum hany kuldetest lehet teljesiteni az i. elott
vector<pair<int, pair<int, int> > > sz;
int tav(int a, int b) {
    return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int main()
{
    cin >> n >> m;
    n2=(1<<n), nm=n+m;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz.push_back({c, {a, b}});
    }
    sort(sz.begin(), sz.end());
    for (int i=n; i<nm; i++) {
        auto p=sz[i-n];
        t[i]=p.first, x[i]=p.second.first, y[i]=p.second.second;
    }
    for (int i=0; i<n2; i++) {
        for (int j=0; j<nm; j++) {
            dist[i][j]=sok;
            for (int k=0; k<n; k++) {
                if (i & (1<<k)) {
                    dist[i][j]=min(dist[i][j], tav(k, j));
                }
            }
        }
    }
    for (int i=0; i<n2; i++) {
        for (int j=0; j<=nm+5; j++) {
            dpb[i][j]=sok;
            dpcs[i][j]=-sok;
        }
    }
    for (int i=0; i<n; i++) {
        dpb[1<<i][0]=0;
    }
    for (int i=n; i<nm; i++) {
        dpcs[0][i]=1;
    }
    for (int i=n; i<nm; i++) {
        for (int mask=0; mask<n2; mask++) {
            while (dpb[mask][pos[mask]]<=t[i]) {
                int cnt=pos[mask];
                for (int j=0; j<nm; j++) {
                    if (j<n) {
                        int ert=(mask | (1<<j));
                        dpb[ert][cnt]=min(dpb[ert][cnt], dpb[mask][cnt]+dist[mask][j]);
                    } else {
                        if (t[j]-dpb[mask][cnt]>=dist[mask][j]) {
                            dpcs[mask][j]=max(dpcs[mask][j], cnt+1);
                        }
                    }
                }
                pos[mask]++;
            }
        }
        for (int mask=0; mask<n2; mask++) {
            int cnt=dpcs[mask][i];
            if (cnt<=0) {
                continue;
            }
            ans=max(ans, cnt);
            for (int j=0; j<nm; j++) {
                int mini=min(tav(i, j), dist[mask][j]);

                if (j<n) {
                    int kov=(mask | (1<<j));
                    dpb[kov][cnt]=min(dpb[kov][cnt], t[i]+mini);
                } else if (j>i) {
                    if (t[j]-t[i]>=mini) {
                        dpcs[mask][j]=max(dpcs[mask][j], cnt+1);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
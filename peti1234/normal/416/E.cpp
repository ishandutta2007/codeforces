#include <bits/stdc++.h>

using namespace std;
const int c=501, sok=1e9;
int n, m, el[c][c], tav[c][c], db[c], ans[c][c];
bitset<c> bs[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j) tav[i][j]=sok;
        }
    }
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        el[a][b]=c, el[b][a]=c;
        tav[a][b]=c, tav[b][a]=c;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                tav[i][j]=min(tav[i][j], tav[i][k]+tav[k][j]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (el[i][j] && el[i][j]!=tav[i][j]) {
                el[i][j]=0;
            }
        }
    }
    for (int kezd=1; kezd<=n; kezd++) {
        vector<pair<int, int> > sz;
        for (int i=1; i<=n; i++) {
            bs[i]=0, db[i]=0;
        }
        for (int i=1; i<=n; i++) {
            sz.push_back({tav[kezd][i], i});
        }
        sort(sz.begin(), sz.end());
        for (auto x:sz) {
            int a=x.second;
            bs[a][a]=1;
            for (int i=1; i<=n; i++) {
                if (el[i][a] && tav[kezd][a]==tav[kezd][i]+el[i][a]) {
                    db[a]++;
                    bs[a]|=bs[i];
                }
            }
            for (int i=1; i<=n; i++) {
                if (bs[a][i]) {
                    ans[kezd][a]+=db[i];
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            cout << ans[i][j] << " ";
        }
    }
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int c=602, c2=100002;
int n, w, m, k, maxi, t[c][c], db[c];
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> m >> k;
        sz.clear();
        maxi=0;
        for (int i=1; i<=k; i++) {
            cin >> db[i];
            maxi=max(maxi, db[i]);
            for (int j=1; j<=db[i]; j++) {
                sz.push_back({-db[i], i});
            }
        }
        sort(sz.begin(), sz.end());
        n=0;
        while (n*n-n*(n/2)<maxi || n*n-(n/2)*(n/2)<m) {
            n++;
        }
        cout << n << "\n";
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                t[i][j]=0;
            }
        }
        int pos=0;
        for (int i=1; i<=n; i+=2) {
            for (int j=2; j<=n; j+=2) {
                if (pos<m) {
                    t[i][j]=sz[pos].second;
                    pos++;
                }
            }
        }
        for (int i=1; i<=n; i+=2) {
            for (int j=1; j<=n; j+=2) {
                if (pos<m) {
                    t[i][j]=sz[pos].second;
                    pos++;
                }
            }
        }
        for (int i=2; i<=n; i+=2) {
            for (int j=1; j<=n; j+=2) {
                if (pos<m) {
                    t[i][j]=sz[pos].second;
                    pos++;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << t[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
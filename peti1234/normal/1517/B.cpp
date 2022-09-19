#include <bits/stdc++.h>

using namespace std;
const int c=102;
long long w, sum, n, m, t[c][c], db[c];
vector<pair<int, int> > ert;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        sum=0, ert.clear();
        for (int i=1; i<=n; i++) {
            db[i]=0;
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<m; j++) {
                cin >> t[i][j];
                ert.push_back({t[i][j], i});
            }
            sort(t[i], t[i]+m);
        }
        sort(ert.begin(), ert.end());
        for (int i=0; i<m; i++) {
            db[ert[i].second]++;
        }
        int pos=0;
        for (int i=1; i<=n; i++) {
            int ss[c];
            for (int j=0; j<m; j++) {
                ss[(j+pos)%m]=t[i][j];
            }
            for (int j=0; j<m; j++) {
                t[i][j]=ss[j];
            }
            pos+=db[i];
        }
        for (int i=1; i<=n; i++) {
            for (int j=0; j<m; j++) {
                cout << t[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
/*
1
2 3
2 3 4
1 3 5
*/
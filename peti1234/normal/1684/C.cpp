#include <bits/stdc++.h>

using namespace std;
int w, n, m;
vector<int> t[200005];
bool jo() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<m; j++) {
            if (t[i][j]>t[i][j+1]) {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            t[i].resize(m+1);
            for (int j=1; j<=m; j++) {
                cin >> t[i][j];
            }
        }
        if (jo()) {
            cout << 1 << " " << 1 << "\n";
        } else {
            vector<int> cs;
            for (int i=1; i<=n; i++) {
                for (int j=1; j<m; j++) {
                    if (t[i][j]>t[i][j+1]) {
                        vector<int> regi, uj;
                        for (int k=1; k<=m; k++) {
                            regi.push_back(t[i][k]), uj.push_back(t[i][k]);
                        }
                        sort(uj.begin(), uj.end());
                        for (int k=0; k<m; k++) {
                            if (regi[k]!=uj[k]) {
                                cs.push_back(k+1);
                            }
                        }
                        i=n+1;
                        break;
                    }
                }
            }
            int a=1, b=1;
            if (cs.size()==2) {
                a=cs[0], b=cs[1];
                for (int i=1; i<=n; i++) {
                    swap(t[i][a], t[i][b]);
                }
            }
            if (jo()) {
                cout << a << " " << b << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}
/*
1
2 2
2 1
1 1
*/
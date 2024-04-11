#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, t[c][c], bal[c][c], le[c][c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            t[i][j]=(c-'a'+1);
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=m; j>=1; j--) {
            le[i][j]=(t[i][j]==t[i+1][j] ? le[i+1][j]+1 : 1);
            bal[i][j]=(t[i][j]==t[i][j+1] ? bal[i][j+1]+1 : 1);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x=le[i][j];
            int pos=i+x;
            if (pos<=n && le[pos][j]==x) {
                pos+=x;
                if (pos<=n && le[pos][j]>=x) {
                    pos+=x;
                    int mini=c;
                    for (int k=i; k<pos; k++) {
                        mini=min(mini, bal[k][j]);
                    }
                    ans+=mini;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
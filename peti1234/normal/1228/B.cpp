#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int t[c][c], s[c], o[c], ans=1, n, m, mod=1e9+7;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        for (int j=1; j<=s[i]; j++) {
            t[i][j]=1;
        }
        t[i][s[i]+1]=2;
    }
    for (int i=1; i<=m; i++) {
        cin >> o[i];
        int x=o[i];
        for (int j=1; j<=x; j++) {
            if (t[j][i]==2) {
                cout << 0;
                return 0;
            }
            t[j][i]=1;
        }
        if (t[x+1][i]==1) {
            cout << 0;
            return 0;
        }
        t[x+1][i]=2;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!t[i][j]) {
                ans*=2;
                ans%=mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
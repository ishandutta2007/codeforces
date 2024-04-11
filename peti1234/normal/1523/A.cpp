#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int w, n, m, t[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            t[0][i]=(c=='1');
        }
        m=min(m, n);
        for (int j=1; j<=m; j++) {
            t[j-1][0]=0, t[j-1][n+1]=0;
            for (int i=1; i<=n; i++) {
                t[j][i]=0;
                if (t[j-1][i] || t[j-1][i-1]!=t[j-1][i+1]) {
                    t[j][i]=1;
                }
            }
        }
        for (int i=1; i<=n; i++) {
            cout << t[m][i];
        }
        cout << "\n";
    }
    return 0;
}
/*
1
1 1
1
*/
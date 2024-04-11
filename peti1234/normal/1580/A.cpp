#include <bits/stdc++.h>

using namespace std;
const int c=405;
int w, n, m, t2[c][c], t[c][c], ert[c], ans;
int calc(int a, int b, int c, int d, int ert) {
    int s=t[c][d]+t[a-1][b-1]-t[a-1][d]-t[c][b-1];
    return (ert ? s : (c-a+1)*(d-b+1)-s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char x;
                cin >> x;
                t2[i][j]=(x=='1');
                t[i][j]=(t[i-1][j]+t[i][j-1]-t[i-1][j-1]+t2[i][j]);
            }
        }
        ans=1e9;
        for (int l=2; l<=m; l++) {
            for (int r=l+1; r<m; r++) {
                for (int i=2; i<n; i++) {
                    int s=calc(1, l, i-1, r, 1)+calc(1, l-1, i-1, l-1, 0)+calc(1, r+1, i-1, r+1, 0);
                    ert[i]=calc(i-1, l, i-1, r, 0)-s;
                    if (i>2) {
                        ert[i]=min(ert[i], ert[i-1]);
                    }
                    if (i>=4) {
                        ans=min(ans, s+ert[i-2]+calc(i, l, i, r, 1)+calc(i+1, l, i+1, r, 0)+2-t2[i][l-1]-t2[i][r+1]);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
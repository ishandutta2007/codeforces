#include <bits/stdc++.h>

using namespace std;
const int c=502, f=260;
int n, m, q, kom[c][c][5], ert[c][c], t[c][c];
int dp[c][c][f];
bool negyzet(int a, int b, int sz, int h) {
    int kiss=a-1, nagys=a+h-1, kiso=b-1, nagyo=b+h-1;
    if (kiss<0 || nagys>n || kiso<0 || nagyo>m) {
        return 0;
    }
    int sum=kom[nagys][nagyo][sz]-kom[kiss][nagyo][sz]-kom[nagys][kiso][sz]+kom[kiss][kiso][sz];
    return (sum==h*h);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            int x;
            cin >> c;
            if (c=='R') x=1;
            if (c=='G') x=2;
            if (c=='Y') x=3;
            if (c=='B') x=4;
            for (int k=1; k<=4; k++) {
                kom[i][j][k]=kom[i-1][j][k]+kom[i][j-1][k]-kom[i-1][j-1][k];
            }
            kom[i][j][x]++;
        }
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            ert[i][j]=c;
            for (int k=1; k<=n; k++) {
                if (!negyzet(i-k+1, j-k+1, 1, k) || !negyzet(i-k+1, j+1, 2, k) || !negyzet(i+1, j-k+1, 3, k) || !negyzet(i+1, j+1, 4, k)) {
                    ert[i][j]=k-1;
                    break;
                }
            }
            for (int k=0; k<=ert[i][j]; k++) {
                dp[i][j][k]++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int k=0; k<f; k++) {
                dp[i][j][k]+=dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k];
            }
        }
    }
    for (int i=1; i<=q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        int lo=0, hi=f, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            int aa=a+mid-1, bb=b+mid-1, cc=c-mid, dd=d-mid;
            if (aa>=cc || bb>=dd) {
                hi=mid;
            } else {
                int sum=dp[cc][dd][mid]-dp[aa][dd][mid]-dp[cc][bb][mid]+dp[aa][bb][mid];
                if (sum) {
                    lo=mid;
                } else {
                    hi=mid;
                }
            }
        }
        cout << 4*lo*lo << "\n";

    }
    return 0;
}
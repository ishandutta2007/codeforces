#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int w, n, m, ans, lcp[c][c], lcs[c][c];
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> a >> b;
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                lcp[i][j]=(a[i]==b[j] ? lcp[i+1][j+1]+1 : 0);
                lcs[i][j]=max(lcs[i+1][j], lcs[i][j+1]);
                if (a[i]==b[j]) lcs[i][j]=lcs[i+1][j+1]+1;
            }
        }
        ans=n-lcp[0][0];
        int pos=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=pos; j++) {
                int koz=lcp[i][j];
                if (lcs[i+koz][j+koz]!=m-j-koz) continue;
                int ert=n-i-koz+1+i+i-j;
                ans=min(ans, ert);
            }
            if (pos<m && a[i]==b[pos]) pos++;
        }
        //cout << "valasz............. ";
        cout << (lcs[0][0]<m ? -1 : ans) << "\n";


        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                lcp[i][j]=0, lcs[i][j]=0;
            }
        }
    }
    return 0;
}
/*
1
6 4
bcccbc
cccc
*/
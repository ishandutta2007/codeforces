#include <bits/stdc++.h>

using namespace std;
const int c=505, sok=1e6;
int n, m, k, pi[c], kov[c][2], regi[c][c], uj[c][c], ans[c];
string a, b;
bool jo[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b;
    k=n-m+1;
    for (int i = 1; i < m; i++) {
        int j = pi[i-1];
        while (j > 0 && b[i] != b[j])
            j = pi[j-1];
        if (b[i] == b[j])
            j++;
        pi[i] = j;
    }
    if (b[0]=='0') kov[0][0]=1;
    else kov[0][1]=1;
    for (int i=1; i<=m; i++) {
        for (int j=0; j<2; j++) {
            char k='0'+j;
            if (i<m && b[i]==k) kov[i][j]=i+1;
            else kov[i][j]=kov[pi[i-1]][j];
            //cout << i << " " << j << " " << kov[i][j] << "\n";
        }
    }

    for (int i=0; i<=k; i++) {
        for (int j=0; j<=m; j++) {
            regi[i][j]=sok, uj[i][j]=sok;
        }
    }
    regi[0][0]=0;
    for (int i=0; i<n; i++) {
        for (int db=0; db<=k; db++) {
            for (int len=0; len<m; len++) {
                int f[2];
                f[0]=(a[i]=='0' ? 0 : 1);
                f[1]=1-f[0];

                for (int p=0; p<2; p++) {
                    int ert=kov[len][p];
                    int add=(ert==m ? 1 : 0);
                    if (ert==m) {
                        ert=pi[ert-1];
                    }

                    uj[db+add][ert]=min(uj[db+add][ert], regi[db][len]+f[p]);
                }
            }
        }

        for (int i=0; i<=k; i++) {
            for (int j=0; j<=m; j++) {
                regi[i][j]=uj[i][j];
                uj[i][j]=sok;
            }
        }
    }

    for (int i=0; i<=k; i++) {
        ans[i]=sok;
        for (int len=0; len<m; len++) {
            ans[i]=min(ans[i], regi[i][len]);
        }
        if (ans[i]==sok) {
            ans[i]=-1;
        }
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w, n, a, b;
bool dp[45][45][100][50];
int ut[45][45][100][50], el[45][45][100][45];
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        cin >> s;
        dp[0][0][50][0]=1;
        for (int k=1; k<=n; k++) {
            int ert=(s[k-1]-'0');
            for (int i=0; i<a; i++) {
                for (int j=0; j<b; j++) {
                    for (int dif=0; dif<100; dif++) {
                        if (dp[i][j][dif][k-1]) {
                            int erta=(10*i+ert)%a, ertb=(10*j+ert)%b;
                            dp[erta][j][dif+1][k]=1;
                            ut[erta][j][dif+1][k]=1;
                            el[erta][j][dif+1][k]=i;

                            dp[i][ertb][dif-1][k]=1;
                            ut[i][ertb][dif-1][k]=-1;
                            el[i][ertb][dif-1][k]=j;
                        }
                    }
                }
            }

        }

        int pos=-1;
        for (int dif=50-n+1; dif<=50+n-1; dif++) {
            if (dp[0][0][dif][n] && abs(dif-50)<=abs(pos-50)) {
                pos=dif;
            }
        }
        if (pos==-1) {
            cout << -1 << "\n";
        } else {
            string ans;
            int aa=0, bb=0, dif=pos;
            for (int i=n; i>=1; i--) {
                if (ut[aa][bb][dif][i]==1) {
                    ans+="R";
                    aa=el[aa][bb][dif][i];
                    dif--;
                } else {
                    ans+="B";
                    bb=el[aa][bb][dif][i];
                    dif++;
                }
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }


        for (int i=0; i<a; i++) {
            for (int j=0; j<b; j++) {
                for (int dif=0; dif<100; dif++) {
                    for (int k=0; k<=n; k++) {
                        dp[i][j][dif][k]=0;
                        el[i][j][dif][k]=0;
                        ut[i][j][dif][k]=0;
                    }
                }
            }
        }
    }
    return 0;
}
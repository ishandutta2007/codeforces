#include <bits/stdc++.h>

using namespace std;
const int c=505;
long long sok=1e12;
long long regi[c][c], uj[c][c];
int n, l, k, pos[c], s[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> l >> k;
    for (int i=1; i<=n; i++) {
        cin >> pos[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }

    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            regi[i][j]=sok;
            uj[i][j]=sok;
        }
    }
    regi[1][0]=0;
    for (int i=2; i<=n; i++) {
        for (int ut=1; ut<i; ut++) {
            for (int db=0; db<=k; db++) {
                long long ert=regi[ut][db]+(pos[i]-pos[i-1])*s[ut];
                uj[i][db]=min(uj[i][db], ert);
                uj[ut][db+1]=min(uj[ut][db+1], ert);
            }
        }


        for (int i=1; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                regi[i][j]=uj[i][j];
                uj[i][j]=sok;
            }
        }
    }


    long long mini=sok;
    for (int ut=1; ut<=n; ut++) {
        for (int db=0; db<=k; db++) {
            mini=min(mini, regi[ut][db]+(l-pos[n])*s[ut]);
        }
    }
    cout << mini << "\n";
    return 0;
}
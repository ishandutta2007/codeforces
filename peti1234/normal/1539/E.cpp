#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=18;
int n, m, mini[c][k][2], maxi[c][k][2], lg[c], t[c], dp[c][2], ut[c][2], lep[c];
int calc(int ert, int pos, int id) {
    for (int i=k-1; i>=0; i--) {
        if (pos+(1<<i)<=n+1) {
            //cout << "proba " << pos << " " << i << "\n";
            //cout << mini[pos][i][id] << " " << maxi[pos][i][id] << "\n";
            //cout << "ert " << ert << "\n";
            if (mini[pos][i][id]<=ert && ert<=maxi[pos][i][id]) {
                pos+=(1<<i);
            }
        }
    }
    //cout << "vege " << pos << "\n";
    return pos-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        for (int j=0; j<2; j++) {
            cin >> mini[i][0][j] >> maxi[i][0][j];
        }
    }
    for (int i=2; i<=n; i++) {
        lg[i]=lg[i/2]+1;
    }
    for (int j=1; j<k; j++) {
        for (int i=1; i+(1<<j)<=n+1; i++) {
            int s=i+(1<<(j-1));
            for (int p=0; p<2; p++) {
                mini[i][j][p]=max(mini[i][j-1][p], mini[s][j-1][p]);
                maxi[i][j][p]=min(maxi[i][j-1][p], maxi[s][j-1][p]);
            }
        }
    }
    //calc(0, 1, 1);
    //return 0;
    dp[0][0]=calc(0, 1, 0), dp[0][1]=calc(0, 1, 1);
    //cout << "vege " << dp[0][0] << " " << dp[0][1] << "\n";
    for (int i=1; i<=n; i++) {
        int bal=calc(t[i], i, 0), jobb=calc(t[i], i, 1);
        //cout << i << " " << bal << " " << jobb << "\n";
        if (dp[i-1][0]>=i && jobb>=i) {
            if (dp[i-1][0]>=dp[i][0]) {
                dp[i][0]=dp[i-1][0];
                ut[i][0]=1;
            }
            if (jobb>dp[i][1]) {
                //cout << "siker "<< i << "\n";
                dp[i][1]=jobb;
                ut[i][1]=1;
            }
        }

        if (dp[i-1][1]>=i && bal>=i) {
            if (dp[i-1][1]>=dp[i][1]) {
                dp[i][1]=dp[i-1][1];
                ut[i][1]=0;
            }
            if (bal>dp[i][0]) {
                dp[i][0]=bal;
                ut[i][0]=0;
            }
        }
    }
    bool pos=0;
    if (dp[n][0]>=n) {
        pos=0;
    } else if (dp[n][1]>=n) {
        pos=1;
    } else {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i=n; i>=1; i--) {
        lep[i]=ut[i][pos];
        pos=1-lep[i];
    }
    for (int i=1; i<=n; i++) {
        cout << lep[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
2 10
3
0 3
0 3
7
4 7
1 3
*/
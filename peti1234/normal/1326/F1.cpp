#include <bits/stdc++.h>

using namespace std;
const int c=14;
int n, dp[1<<c][1<<7][c], m, k, s, valt[1<<c];
long long ans[1<<c];
bool v[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    m=(1<<n), k=(1<<(n/2)), s=n/2+1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char x; cin >> x;
            if (x=='1') {
                v[i][j]=1;
            }
        }
    }
    for (int i=0; i<n; i++) {
        dp[1<<i][0][i]=1;
    }
    for (int i=1; i<m; i++) {
        int db=__builtin_popcount(i);
        if (2*db<=n)
        for (int j=0; j<k; j++) {
            for (int x=0; x<n; x++) {
                if (dp[i][j][x]) {
                    for (int y=0; y<n; y++) {
                        if ((i&(1<<y))==0) {
                            int sp=(v[x][y]<<(db-1));
                            dp[i+(1<<y)][j+sp][y]+=dp[i][j][x];
                        }
                    }
                }
            }
        }
    }

    for (int i=0; i<k; i++) {
        int st=1<<(n-2), ert=0, x=i;
        while(x) {
            if (x%2) {
                ert+=st;
            }
            st/=2, x/=2;
        }
        valt[i]=ert;
        //cout << i << " " << valt[i] << endl;
    }
    for (int i=1; i<m; i++) {
        int db=__builtin_popcount(i);
        if (db==s) {
            for (int x=0; x<n; x++) {
                if (i&(1<<x)) {
                    int inv=m-1-i+(1<<x);
                    //cout << "lehet " << i << " " << inv << endl;
                    for (int a=0; a<k; a++) {
                        for (int b=0; b<k; b++) {
                            int aa=dp[i][a][x], bb=dp[inv][b][x];
                            if (aa && bb) {
                                ans[a+valt[b]]+=aa*bb;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=0; i<m/2; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
2
01
10
*/
// long long
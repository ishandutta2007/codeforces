#include <bits/stdc++.h>

using namespace std;
const int c=16, c2=(1<<15), sok=1e8;
int w, n, m, t[c], sum[c2], dp[c][c][c2], lep[c][c][c2], ans, val[c];
void calc(int i, int j, int mask, int uj, int sub) {
    if (uj<dp[i][j][mask]) {
        dp[i][j][mask]=uj;
        lep[i][j][mask]=sub;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        m=(1<<n);
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=0; i<m; i++) {
            int ert=0;
            for (int j=0; j<n; j++) {
                if (i & (1<<j)) {
                    ert+=t[j+1];
                }
            }
            sum[i]=ert;
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                for (int k=0; k<m; k++) {
                    dp[i][j][k]=sok;
                    lep[i][j][k]=0;
                }
            }
        }
        dp[0][0][m-1]=0;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                for (int mask=0; mask<m; mask++) {
                    int el=dp[i-1][j][mask];
                    if (el==sok) {
                        continue;
                    }
                    calc(i, j, mask, el, 0);
                    //dp[i][j][mask]=min(dp[i][j][mask], el);
                    if ((mask & (1<<(i-1))) == 0) {
                        continue;
                    }
                    int k=1<<(i-1), m2=mask-k;
                    if (t[i]>el) {
                        //dp[i][j][m2]=min(dp[i][j][m2], t[i]);
                        calc(i, j, m2, t[i], k);
                    }
                    for (int sub=m2; sub>0; sub=(sub-1)&m2) {
                        if (t[i]+sum[sub]>el) {
                            int db=__builtin_popcount(sub)+j;
                            //dp[i][db][m2-sub]=min(dp[i][db][m2-sub], t[i]+sum[sub]);
                            calc(i, db, m2-sub, t[i]+sum[sub], sub+k);
                        }
                    }
                }
            }
        }
        for (int i=0; i<=n; i++) {
            if (dp[n][i][0]<sok) {
                ans=i;
                break;
            }
        }
        for (int i=1; i<=n; i++) {
            val[i]=i;
        }
        //cout << "valasz: ";
        cout << ans << "\n";
        int ert=0, cnt=ans;
        for (int i=n; i>=1; i--) {
            int mask=lep[i][cnt][ert];
            for (int j=0; j<n; j++) {
                if ((1<<j) & mask) {
                    if (j+1!=i) {
                        cout << val[j+1] << " " << val[i] << "\n";
                        for (int valt=j+2; valt<=n; valt++) {
                            val[valt]--;
                        }
                        cnt--;
                    }
                }
            }
            ert+=mask;
        }
    }
    return 0;
}
/*
1
15
16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
*/
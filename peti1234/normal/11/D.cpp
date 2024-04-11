#include <bits/stdc++.h>

using namespace std;
const int c=19, c2=1<<c;
int n, n2, m;
long long dp[c2][c], ans;
bool el[c][c];
int main()
{
    cin >> n >> m;
    n2=1<<n;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        el[a][b]=el[b][a]=true;
    }
    for (int kezd=n-1; kezd>=1; kezd--) {
        dp[1<<kezd][kezd]=1;
        for (int mask=1<<kezd; mask<(2<<kezd); mask++) {
            //cout << "ertek " << kezd << " " << mask << "\n";
            for (int pos=0; pos<=kezd; pos++) {
                //cout << "fontos " << dp[mask][pos] << "\n";
                for (int kov=0; kov<=kezd; kov++) {
                    if (el[pos][kov] && (mask & (1<<kov))==0) {
                        dp[mask+(1<<kov)][kov]+=dp[mask][pos];
                    }
                }
                if (el[pos][kezd] && __builtin_popcount(mask)>=3) {
                    ans+=dp[mask][pos];
                }
            }
        }
        for (int i=0; i<n2; i++) {
            for (int j=0; j<n; j++) {
                dp[i][j]=0;
            }
        }
    }
    //cout << "vege " << ans << "\n";
    cout << ans/2 << "\n";
    return 0;
}
/*
3 3
1 2
2 3
3 1

*/
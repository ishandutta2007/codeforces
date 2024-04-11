#include <bits/stdc++.h>

using namespace std;
const int c=205;
long long n, dp[c][c], ans[c], t[c][c], pref[c][c], ert[c][c], opt[c][c];
bool v[c][c];
long long solve(int a, int b) {
    if (a>b) return 0;
    if (!v[a][b]) {
        long long pos=a, mini=1e18;
        for (int i=a; i<=b; i++) {
            long long p=ert[a][i-1]+ert[i+1][b]+solve(a, i-1)+solve(i+1, b);
            if (p<mini) {
                mini=p;
                pos=i;
            }
        }
        v[a][b]=1;
        dp[a][b]=mini;
        opt[a][b]=pos;
    }
    return dp[a][b];
}
void solve2(int a, int b, int ut) {
    if (a>b) return;
    int x=opt[a][b];
    ans[x]=ut;
    solve2(a, x-1, x), solve2(x+1, b, x);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[i][j];
            pref[i][j]=(pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+t[i][j]);
        }
    }
    for (int kezd=1; kezd<=n; kezd++) {
        for (int veg=kezd; veg<=n; veg++) {
            ert[kezd][veg]=pref[n][veg]-pref[n][kezd-1]-pref[veg][veg]+pref[veg][kezd-1]+pref[kezd-1][veg]-pref[kezd-1][kezd-1];
            //cout << kezd << " " << veg << " " << ert[kezd][veg] << "\n";
        }
    }
    solve(1, n);
    solve2(1, n, 0);
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
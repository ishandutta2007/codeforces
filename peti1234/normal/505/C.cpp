#include <bits/stdc++.h>

using namespace std;
const int c=30002, k=1002, f=501;
int db[c], dp[c][k], n, d, maxi;
void valt(int a, int b, int s) {
    if (a>=c) return;
    dp[a][b]=max(dp[a][b], s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> d;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        db[x]++;
    }
    dp[d][f]=1;
    for (int i=1; i<c; i++) {
        for (int j=0; j<k; j++) {
            if (dp[i][j]) {
                dp[i][j]+=db[i];
                int ert=d+j-f, s=dp[i][j];
                maxi=max(maxi, s);
                valt(i+ert+1, j+1, s);
                valt(i+ert, j, s);
                valt(i+ert-1, j-1, s);
            }
        }
    }
    cout << maxi-1 << "\n";
    return 0;
}
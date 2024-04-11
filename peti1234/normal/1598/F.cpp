#include <bits/stdc++.h>

using namespace std;
const int c=20, c2=1<<c, k=400005;
int n, n2, db[c], mini[c], add[c][k];
int dp[c2], sum[c2], ans=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    n2=(1<<n);
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        int cnt=0, kis=0;
        for (auto c:s) {
            if (c=='(') {
                cnt++;
            } else {
                cnt--;
                kis=min(kis, cnt);
                if (cnt==kis) {
                    add[i][-cnt]++;
                }
            }
        }
        mini[i]=kis;
        db[i]=cnt;
        for (int j=0; j<n2; j++) {
            if (j & (1<<i)) {
                sum[j]+=cnt;
            }
        }
    }
    for (int i=1; i<n2; i++) {
        dp[i]=-k;
        for (int j=0; j<n; j++) {
            if (i & (1<<j)) {
                int el=i-(1<<j);
                if (sum[el]>=0) {
                    int s=dp[el]+add[j][sum[el]];
                    ans=max(ans, s);
                    if (sum[el]+mini[j]>=0) {
                        dp[i]=max(dp[i], s);
                    }
                }

            }
        }
    }
    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
long long n, k, h;
long long dp[300001][4];
int main()
{
    cin >> n >> k;
    h=(1<<n);
    for (long long i=1; i<2*h; i++) for (long long j=1; j<4; j++) dp[i][j]=-10000000000;
    for (long long i=1; i<=k; i++) {
        long long x;
        cin >> x;
        dp[h+x-1][1]=0;
    }
    for (long long i=h-1; i>=1; i--) {
        long long a=2*i, b=2*i+1;
        long long ae=dp[a][0], am=dp[a][1], ah=dp[a][2], an=dp[a][3];
        long long be=dp[b][0], bm=dp[b][1], bh=dp[b][2], bn=dp[b][3];
        long long amax=max({ae, am, ah, an}), bmax=max({be, bm, bh, bn});
        //cout << i << " " << ae << " " << am << " " << ah << " " << an << " " << be << " " << bm << " " << bh << " " << bn << endl;
        dp[i][0]=ae+be;
        dp[i][1]=max({dp[i][1], ae+bm+1, am+be+1});
        dp[i][2]=max({dp[i][2], ah+be+2, bh+ae+2, ah+bh+2, am+be+2, ae+bm+2});
        dp[i][3]=max({dp[i][3], 3+an+bmax, 3+bn+amax, 3+am+bh, 3+ah+bm, 2+am+bm});
        if (i>=h/2) dp[i][2]--, dp[i][3]--;
        //cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
        dp[i][2]=max(dp[i][2], dp[i][3]);
        dp[i][1]=max(dp[i][1], dp[i][3]);
        dp[i][0]=max({dp[i][0], dp[i][1], dp[i][2]});
    }
    if (k) dp[1][0]++;
    cout << dp[1][0] << endl;
    return 0;
}
/*
3 8
1 2 3 4 5 6 7 8
*/
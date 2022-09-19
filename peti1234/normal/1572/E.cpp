#include <bits/stdc++.h>

using namespace std;
const int c=205;
long long n, cnt, x[c], y[c], t[c][c], t2[c][c][c];
pair<long long, long long> dp[c][c];
int main()
{
    cin >> n >> cnt;
    cnt++;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            long long sum=(x[j]-x[i])*(y[j]+y[i]);
            int k=i;
            do {
                int kov=(k+1)%n;
                sum+=(x[k]-x[kov])*(y[k]+y[kov]);
                k=kov;
            } while (k!=j);
            t[i][j]=sum;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                t2[i][j][k]=(t[i][k]-t[i][j]-t[j][k]);
            }
        }
    }
    long long lo=0, hi=t[0][0]/cnt+1, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        for (int dif=2; dif<=n; dif++) {
            for (int kezd=0; kezd<=n-dif; kezd++) {
                int veg=(kezd+dif)%n;
                if (t[kezd][veg]>=mid) dp[kezd][veg]={1, 0};
                else dp[kezd][veg]={0, t[kezd][veg]};
                for (int s=1; s<dif; s++) {
                    int koz=(kezd+s)%n;
                    long long db=dp[kezd][koz].first+dp[koz][veg].first, ert=dp[kezd][koz].second+dp[koz][veg].second+t2[kezd][koz][veg];
                    if (ert>=mid) {
                        db++;
                        ert=0;
                    }
                    dp[kezd][veg]=max(dp[kezd][veg], {db, ert});
                }
            }
        }
        if (dp[0][0].first>=cnt) lo=mid;
        else hi=mid;
    }
    cout << lo << "\n";
    return 0;
}
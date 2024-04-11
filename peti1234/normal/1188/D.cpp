#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=65;
long long n, maxi, t[c], dp[k][c], e[k], p=2, bit[k][c], db;
vector<pair<long long, long long> >v[65];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (long long i=1; i<=n; i++) {
        t[i]=t[n]-t[i];
    }
    maxi=t[1];
    for (long long j=1; p<=4*maxi; j++) {
        db=j;
        for (long long i=1; i<=n; i++) {
            if (t[i]%p>t[i]%(p/2)) {
                e[j]++;
                bit[j][i]=1;
            } else {
                bit[j][i]=0;
            }
            v[j].push_back({t[i]%p, i});
        }
        p*=2;
        sort(v[j].rbegin(), v[j].rend());
    }
    if (maxi==0) {
        cout << 0;
        return 0;
    }
    for (long long i=1; i<=db; i++) {
        for (long long j=0; j<=n; j++) {
            dp[i][j]=INT_MAX;
        }
    }
    dp[1][0]=e[1];
    dp[1][e[1]]=min(dp[1][e[1]], n-e[1]);
    for (long long i=2; i<=db; i++) {
        long long pl=0;
        for (long long j=0; j<=n; j++) {
            if (j>0 && bit[i][v[i-1][j-1].second]==1) {
                pl++;
            }
            if (dp[i-1][j]!=INT_MAX) {
                long long a=dp[i-1][j];
                long long ee=e[i];
                dp[i][pl]=min(dp[i][pl], a+ee+j-2*pl);
                dp[i][ee+j-pl]=min(dp[i][ee+j-pl], a+n-ee-j+2*pl);
            }
        }
    }

    long long mini=INT_MAX;
    for (long long i=0; i<=n; i++) {
        mini=min(mini, dp[db][i]+i);
    }
    cout << mini << endl;
    return 0;
}
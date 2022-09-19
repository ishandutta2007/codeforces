#include <bits/stdc++.h>

using namespace std;
long long sum;
long long dp[501];
vector<pair<long long, pair<long long, long long> > > sz;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a>b*c) {
            sum+=a;
            sum-=b*c;
            a=b*c;
        }
        sz.push_back({b, {a, c}});
    }
    sort(sz.begin(), sz.end());
    reverse(sz.begin(), sz.end());
    for (long long i=0; i<sz.size(); i++) {
        for (long long j=n-1; j>=0; j--) {
            long long fi=sz[i].first;
            long long sefi=sz[i].second.first;
            long long sese=sz[i].second.second;
            dp[j+1]=max(dp[j+1], dp[j]+sefi-fi*(min(j, sese)));
        }
    }
    long long maxi=0;
    for (int i=0; i<=n; i++) {
        maxi=max(maxi, dp[i]);
    }
    cout << sum+maxi << endl;
    return 0;
}
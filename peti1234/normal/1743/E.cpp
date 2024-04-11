#include <bits/stdc++.h>

using namespace std;
long long p1, t1, p2, t2, h, s, dp[5005], sok=1e18;
vector<pair<long long, long long> > sz;
int main()
{
    cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
    sz.push_back({0, 0});
    if (p1>s) {
        for (int i=1; i<=h; i++) {
            sz.push_back({t1*i, p1-s});
        }
    }
    if (p2>s) {
        for (int i=1; i<=h; i++) {
            sz.push_back({t2*i, p2-s});
        }
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<=h; i++) {
        dp[i]=sok;
    }
    for (int i=0; i<h; i++) {
        long long t=0, sum=0;
        for (auto x:sz) {
            t=x.first, sum+=x.second;
            if (i+sum>=h) {
                dp[h]=min(dp[h], dp[i]+t);
            }
            long long kov=min(h, i+sum+p1+p2-s), ert=(t==0 ? max(t1, t2) : max(t1-t%t1, t2-t%t2));
            dp[kov]=min(dp[kov], dp[i]+t+ert);
        }
    }
    cout << dp[h] << "\n";
    return 0;
}
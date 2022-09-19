#include <bits/stdc++.h>

using namespace std;
const long long mod=1e18, c=5e5+1;
long long t[c], db[c], x[c], y[c], z[c], n, sum, ans;
int maxi;
vector<int> sz[c];
vector<pair<long long, pair<int, int> > > res;
long long vel() {
    long long a=rand(), b=rand(), c=rand(), d=rand();
    return a*b*c+d;
}
int main()
{
    for (int i=1; i<=c; i++) {
        x[i]=vel(), y[i]=vel(), z[i]=mod-x[i]-y[i];
    }
    cin >> n;
    res.push_back({0, {0, 0}});
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sz[t[i]].push_back(i);
        int si=sz[t[i]].size();
        if (si%3==1) sum+=x[t[i]];
        if (si%3==2) sum+=y[t[i]];
        if (si%3==0) sum+=z[t[i]];
        if (si>3) {
            maxi=max(maxi, sz[t[i]][si-4]);
        }
        sum%=mod;
        res.push_back({sum, {i, maxi}});
    }
    sort(res.begin(), res.end());
    for (int i=0; i<res.size(); i++) {
        int lo=-1, hi=i, mid;
        while(hi-lo>1) {
            mid=(hi+lo)/2;
            if (res[mid].first<res[i].first || res[i].second.second>res[mid].second.first) lo=mid;
            else hi=mid;
        }
        ans+=i-hi;
    }
    cout << ans << "\n";
    return 0;
}
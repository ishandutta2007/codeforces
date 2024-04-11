#include <bits/stdc++.h>

using namespace std;
const int c=200005, sok=2e9;
long long n, m, k, s, p1[c], p2[c], k1[c], k2[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >>s;
    for (int i=1; i<=n; i++) cin >> p1[i];
    for (int i=1; i<=n; i++) cin >> p2[i];
    for (int i=1; i<=m; i++) {
        int id, ert;
        cin >> id >> ert;
        k1[i]=(id==1 ? ert : sok);
        k2[i]=(id==2 ? ert : sok);
    }
    int lo=0, hi=n+1, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        int pos1=1, pos2=1;
        for (int i=1; i<=mid; i++) {
            if (p1[i]<p1[pos1]) pos1=i;
            if (p2[i]<p2[pos2]) pos2=i;
        }
        long long sum=0;
        vector<long long> sz;
        for (int i=1; i<=m; i++) {
            sz.push_back(min(k1[i]*p1[pos1], k2[i]*p2[pos2]));
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<k; i++) sum+=sz[i];
        if (sum>s) lo=mid;
        else hi=mid;
    }
    if (hi==n+1) cout << -1 << "\n";
    else {
        cout << hi << "\n";
        int pos1=1, pos2=1;
        for (int i=1; i<=hi; i++) {
            if (p1[i]<p1[pos1]) pos1=i;
            if (p2[i]<p2[pos2]) pos2=i;
        }
        long long sum=0;
        vector<pair<long long, int> > sz;
        for (int i=1; i<=m; i++) {
            sz.push_back({min(k1[i]*p1[pos1], k2[i]*p2[pos2]), i});
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<k; i++) {
            long long ert=sz[i].first, id=sz[i].second;
            cout << id << " " << (ert==k1[id]*p1[pos1] ? pos1 : pos2) << "\n";
        }
    }
    return 0;
}
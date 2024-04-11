#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, m, q, db[c], ki[c];
long long pref[c], sum, ans[c];
vector<pair<int, int> > sz, dist, qu;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
long long calc(int a) {
    return pref[a]-pref[a-db[a]];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    sz.push_back({0, 0});
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sum+=x;
        sz.push_back({x, 1});
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        sz.push_back({x, 0});
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<=n+m; i++) {
        db[i]=sz[i].second;
        pref[i]=pref[i-1]+sz[i].first;
        dist.push_back({sz[i].first-sz[i-1].first, i});
    }
    sort(dist.begin(), dist.end());
    for (int i=1; i<=q; i++) {
        int x;
        cin >> x;
        qu.push_back({x, i});
    }
    sort(qu.begin(), qu.end());
    int pos=0;
    for (auto x:qu) {
        while (pos<n+m && dist[pos].first<=x.first) {
            int a=dist[pos].second-1, b=a+1;
            b=holvan(b);
            ki[a]=b;
            sum-=calc(a), sum-=calc(b);
            db[b]+=db[a], sum+=calc(b);
            pos++;
        }
        ans[x.second]=sum;
    }
    for (int i=1; i<=q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
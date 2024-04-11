#include <bits/stdc++.h>

using namespace std;
int n, m, s, k, q;
vector<pair<int, pair<int, int>>>sz;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> n >> m >> k >> s;
        sz.clear();
        bool sol=true;
        for (int i=1; i<=n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            sz.push_back({a, {c, b}});
        }
        long long ans=0, kesz=0, sum=0;
        sz.push_back({0, {0, s}}), sz.push_back({m, {0, 0}});
        sort(sz.begin(), sz.end());
        map<int, int> p;
        for (int i=0; i<sz.size(); i++) {
            int ido=sz[i].first, ar=sz[i].second.first, db=sz[i].second.second;
            while(!p.empty() && kesz!=ido) {
                long long x=p.begin()->first, y=p.begin()->second, mini=min(y, ido-kesz);
                kesz+=mini, sum-=mini, ans+=x*mini;
                p.begin()->second-=mini;
                if (p.begin()->second==0) p.erase(p.begin());
            }
            if (kesz!=ido) sol=false;
            p[ar]+=db, sum+=db;
            while(sum>k) {
                int x=p.rbegin()->first;
                long long y=p.rbegin()->second, mini=min(y, sum-k);
                sum-=mini, p.rbegin()->second-=mini;
                if (p.rbegin()->second==0) p.erase(--p.end());
            }
        }
        if (!sol) ans=-1;
        cout << ans << "\n";
    }
    return 0;
}
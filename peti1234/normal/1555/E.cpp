#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, m, ans=c, maxi;
vector<pair<int, pair<int, int> > > sz;
vector<int> pl[c], mi[c], fel[c];
set<pair<int, int> > s;
pair<int, int> conv(int x) {
    return {sz[x].first, x};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    sz.push_back({-c, {0, 0}});
    sz.push_back({2*c, {0, 0}});
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz.push_back({c, {a, b}});
    }

    sort(sz.begin(), sz.end());
    for (int i=1; i<=n; i++) {
        int a=sz[i].second.first, b=sz[i].second.second;
        pl[a].push_back(i), mi[b].push_back(i);
    }

    s.insert({-c, 0}), s.insert({2*c, n+1});
    for (int i=1; i<m; i++) {

        for (auto x:pl[i]) {
            auto xx=conv(x);
            s.insert(xx);
        }
        for (auto x:pl[i]) {
            auto xx=conv(x);
            auto it=s.find(xx), el=it, kov=it;
            el--, kov++;
            fel[(*el).second].push_back((*it).second);
            fel[(*it).second].push_back((*kov).second);
        }
        for (auto x:mi[i]) {
            auto xx=conv(x);
            auto it=s.find(xx), el=it, kov=it;
            el--, kov++;
            fel[(*el).second].push_back((*kov).second);
            s.erase(xx);
        }
    }
    for (auto x:fel[0]) {
        maxi=max(maxi, conv(x).first);
    }
    for (int i=1; i<=n; i++) {
        ans=min(ans, maxi-sz[i].first);
        //cout << "proba " << maxi << " " << sz[i].first << "\n";
        for (auto x:fel[i]) {
            maxi=max(maxi, conv(x).first);
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
4 3
1 2 3
2 3 5
1 2 7
2 3 8
*/
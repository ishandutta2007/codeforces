#include <bits/stdc++.h>

using namespace std;
int n, m, mini, jobb;
vector<pair<int, int> > sz, x, y;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        x.push_back({a, b});
    }
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        y.push_back({a, b});
    }
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        int a=x[i].first, b=x[i].second, c=y[j].first, d=y[j].second;
        if (a<=c && b<=d) sz.push_back({c-a+1, d-b+1}), mini=max(mini, d-b+1);
    }
    sort(sz.rbegin(), sz.rend());
    if (sz.size()==0) {
        cout << 0 << "\n";
    } else {
        mini=min(mini, sz[0].first), jobb=sz[0].second;
        for (int i=1; i<sz.size(); i++) {
            mini=min(mini, jobb+sz[i].first);
            jobb=max(jobb, sz[i].second);
        }
        cout << mini << "\n";
    }
    return 0;
}
/*
1 1
0 0
5 5
*/
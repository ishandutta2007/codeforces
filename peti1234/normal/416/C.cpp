#include <bits/stdc++.h>

using namespace std;
int n, m, sum;
vector<pair<int, pair<int, int> > > sz;
priority_queue<pair<int, int> > q;
vector<pair<int, int> > ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({a, {-b, i}});
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int a;
        cin >> a;
        sz.push_back({a, {0, i}});
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        int ert=x.second.first, id=x.second.second;
        if (ert<0) {
            q.push({-ert, id});
        } else {
            if (q.size()>0) {
                sum+=q.top().first;
                ans.push_back({q.top().second, id});
                q.pop();
            }
        }
    }
    cout << ans.size() << " " << sum << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
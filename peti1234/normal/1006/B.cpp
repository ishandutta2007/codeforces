#include <bits/stdc++.h>

using namespace std;
int n, k, sum, x;
vector<pair<int, int> > sz;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<k; i++) {
        sum+=sz[i].first;
        ans.push_back(sz[i].second);
    }
    ans.push_back(0);
    sort(ans.begin(), ans.end());
    ans.back()=n;
    cout << sum << "\n";
    for (int i=1; i<=k; i++) {
        cout << ans[i]-ans[i-1] << " ";
    }
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, ans[c], cnt=0;
vector<pair<int, int> > sz;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back({x, 0});
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        sz.push_back({x, i});
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        int se=x.second;
        if (!se) cnt++;
        else ans[se]=cnt;
    }
    for (int i=1; i<=m; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
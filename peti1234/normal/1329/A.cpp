#include <bits/stdc++.h>

using namespace std;
int n, m, x, a;
vector<pair<int, int> > t;
int ans[100002];
long long sum;
bool h=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        t.push_back({x, i});
        sum+=x;
    }
    reverse(t.begin(), t.end());
    if (sum<n) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=0; i<m; i++) {
        if (m-i-1+t[i].first>n) {
            cout << -1 << "\n";
            return 0;
        }
    }
    a=n;
    for (int i=0; i<m; i++) {
        int id=t[i].second, er=t[i].first;
        sum-=er;
        while ((a+er-1>n) || (sum+1<a)) a--;
        ans[id]=a, a--;
    }
    for (int i=1; i<=m; i++) cout << ans[i] << " ";
    return 0;
}
// Trkks feladat, nem gondoltam t teljesen a megoldst.
// Nha clszer a b-re is rnzni.
#include <bits/stdc++.h>

using namespace std;
long long n, m, sum;
vector<pair<long long, long long> > sz;
int main()
{
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        int x, y; cin >> x >> y;
        sz.push_back({y, x});
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<n; i++) {
        long long fi=sz[i].first, se=sz[i].second, p=min(m, se);
        m-=p, sum+=fi*p;
    }
    cout << sum << "\n";
    return 0;
}
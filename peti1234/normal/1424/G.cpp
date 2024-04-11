#include <bits/stdc++.h>

using namespace std;
int n, db, maxi, t;
vector<pair<int, int>> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        sz.push_back({a, 1}), sz.push_back({b, -1});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<sz.size(); i++) {
        int a=sz[i].first, b=sz[i].second;
        db+=b;
        if (db>maxi) {
            maxi=db, t=a;
        }
    }
    cout << t << " " << maxi << "\n";
    return 0;
}
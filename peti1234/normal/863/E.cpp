#include <bits/stdc++.h>

using namespace std;
int n, veg[200002];
vector<pair<pair<int, int>, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        sz.push_back({{x, y+1}, i});
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<n; i++) {
        if (sz[i].first.first==sz[i-1].first.first) {
            cout << sz[i-1].second << "\n";
            return 0;
        }
        if (sz[i].first.second<=sz[i-1].first.second) {
            cout << sz[i].second << "\n";
            return 0;
        }
    }
    for (int i=0; i<n-2; i++) {
        if (sz[i].first.second>=sz[i+2].first.first) {
            cout << sz[i+1].second << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
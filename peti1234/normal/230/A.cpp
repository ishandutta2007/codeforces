#include <bits/stdc++.h>

using namespace std;
int n, s;
vector<pair<int, int> >sz;
int main()
{
    cin >> s >> n;
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        sz.push_back({x, y});
    }
    sort(sz.begin(), sz.end());
    bool jo=1;
    for (int i=0; i<n; i++) {
        if (s<=sz[i].first) jo=0;
        s+=sz[i].second;
    }
    if (jo) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
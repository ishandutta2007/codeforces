#include <bits/stdc++.h>

using namespace std;
int n, m, s;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            sz.push_back({i, j});
        }
    }
    s=n*m;
    for (int i=0; i<s/2; i++) {
        cout << sz[i].first << " " << sz[i].second << "\n";
        cout << sz[s-i-1].first << " " << sz[s-i-1].second << "\n";
    }
    if (s%2) {
        cout << sz[s/2].first << " " << sz[s/2].second << "\n";
    }
    return 0;
}
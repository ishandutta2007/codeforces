#include <bits/stdc++.h>

using namespace std;
int n, m, ans;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<m; i++) {
        ans-=min(0, sz[i]);
    }
    cout << ans << "\n";
    return 0;
}
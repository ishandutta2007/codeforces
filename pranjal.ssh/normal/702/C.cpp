#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (j + 1 < m && abs(a[i] - b[j + 1]) <= abs(a[i] - b[j])) ++j;
        ans = max(ans, abs(a[i] - b[j]));
    }
    cout << ans;
    return 0;
}
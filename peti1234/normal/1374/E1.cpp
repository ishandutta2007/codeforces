#include <bits/stdc++.h>

using namespace std;
int n, m, sum;
vector<int> a, b, o;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (y && z) o.push_back(x);
        else if (y) a.push_back(x);
        else if (z) b.push_back(x);
    }
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    for (int i=0; i<min(a.size(), b.size()); i++) o.push_back(a[i]+b[i]);
    sort(o.begin(), o.end());
    if (o.size()<m) cout << -1 << "\n";
    else {
        for (int i=0; i<m; i++) sum+=o[i];
        cout << sum << "\n";
    }
    return 0;
}
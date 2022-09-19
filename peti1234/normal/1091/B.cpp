#include <bits/stdc++.h>

using namespace std;
int k=1e7, n, amin=k, bmin=k, xmax=-k, ymax=-k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        amin=min(amin, a), bmin=min(bmin, b);
    }
    for (int i=1; i<=n; i++) {
        int x, y; cin >> x >> y;
        xmax=max(xmax, x), ymax=max(ymax, y);
    }
    cout << amin+xmax << " " << bmin+ymax << "\n";
    return 0;
}
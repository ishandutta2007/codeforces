#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m, a[c], b[c], x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    cout << (a[x]<b[m+1-y] ? "YES" : "NO") << "\n";
    return 0;
}
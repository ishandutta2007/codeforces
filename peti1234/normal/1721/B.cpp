#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, m, a, b, d;
    cin >> n >> m >> a >> b >> d;
    if (a-d<=1 && b-d<=1 || a+d>=n && b+d>=m || a-d<=1 && a+d>=n || b-d<=1 && b+d>=m) cout << -1 << "\n";
    else cout << n+m-2 << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
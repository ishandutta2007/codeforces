#include <bits/stdc++.h>

using namespace std;
int tc, n, m, x1, yl, x2, y2, w, h, dx, dy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> x1 >> yl >> x2 >> y2 >> w >> h;
        dx=x2-x1, dy=y2-yl;
        int mini=1e9;
        if (dx+w<=n) {
            mini=min({mini, w-x1, w-n+x2});
        }
        if (dy+h<=m) {
            mini=min({mini, h-yl, h-m+y2});
        }
        //cout << "valasz: ";
        cout << (mini==1e9 ? -1 : max(0, mini)) << "\n";
    }
    return 0;
}
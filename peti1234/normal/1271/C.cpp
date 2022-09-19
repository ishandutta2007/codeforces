#include <bits/stdc++.h>

using namespace std;
int n, x, y, xx, yy, a, b, c, d, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i=1; i<=n; i++) {
        cin >> xx >> yy;
        if (xx>x) {
            a++;
        }
        if (xx<x) {
            b++;
        }
        if (yy>y) {
            c++;
        }
        if (yy<y) {
            d++;
        }
    }
    ans=max({a, b, c, d});
    cout << ans << "\n";
    if (a==ans) {
        cout << x+1 << " " << y << "\n";
    } else if (b==ans) {
        cout << x-1 << " " << y << "\n";
    } else if (c==ans) {
        cout << x << " " << y+1 << "\n";
    } else {
        cout << x << " " << y-1 << "\n";
    }
    return 0;
}
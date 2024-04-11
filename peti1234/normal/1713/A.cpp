#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, a=0, b=0, c=0, d=0;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        a=min(a, x), b=max(b, x), c=min(c, y), d=max(d, y);
    }
    cout << 2*(abs(a)+b+abs(c)+d) << "\n";
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
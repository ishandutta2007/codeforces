#include <bits/stdc++.h>

using namespace std;
int n, x, y, p, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i=1; i<=n; i++) {
        cin >> p;
        if (p<=x) ans++;
    }
    if (x>y) {
        cout << n << "\n";
    } else {
        cout << (ans+1)/2 << "\n";
    }
    return 0;
}
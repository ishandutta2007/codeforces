#include <bits/stdc++.h>

using namespace std;
int n, m;
int a, b=INT_MAX, c, d=INT_MAX;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        a=max(a, x);
        b=min(b, y);
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        c=max(c, x);
        d=min(d, y);
    }
    cout << max(a-d, max(c-b, 0)) << endl;
    return 0;
}
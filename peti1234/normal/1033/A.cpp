#include <bits/stdc++.h>

using namespace std;
int n, a, b, c, d, e, f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> d >> e >> f;
    if (a>min(c, e) && a<max(c, e) || b>min(d, f) && b<max(d, f)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
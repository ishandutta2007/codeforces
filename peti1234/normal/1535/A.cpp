#include <bits/stdc++.h>

using namespace std;
int w, a, b, c, d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b >> c >> d;
        if (min(a, b)<max(c, d) && max(a, b)>min(c, d)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
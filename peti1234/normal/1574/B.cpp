#include <bits/stdc++.h>

using namespace std;
int w, a, b, c, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b >> c >> m;
        int s=(a+b+c), p=max({a, b, c});
        if (2*p-1-s<=m && m<=s-3) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
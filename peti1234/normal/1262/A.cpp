#include <bits/stdc++.h>

using namespace std;
int w, n, bn, jk;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> bn >> jk;
        for (int i=1; i<n; i++) {
            int x, y;
            cin >> x >> y;
            bn=max(bn, x), jk=min(jk, y);
        }
        cout << max(0, bn-jk) << "\n";
    }
    return 0;
}
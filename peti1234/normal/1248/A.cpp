#include <bits/stdc++.h>

using namespace std;
long long w, n, m, ans, o, e;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        o=0, e=0, ans=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x%2) {
                o++;
            } else {
                e++;
            }
        }
        cin >> m;
        for (int i=1; i<=m; i++) {
            int x;
            cin >> x;
            if (x%2) {
                ans+=o;
            } else {
                ans+=e;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
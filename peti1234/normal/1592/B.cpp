#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, x, t[c], r[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> x;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            r[i]=t[i];
        }
        sort(r+1, r+n+1);
        bool baj=0;
        for (int i=1; i<=n; i++) {
            if (r[i]!=t[i]) {
                if (i<=x && i+x>n) {
                    baj=1;
                }
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";

    }
    return 0;
}
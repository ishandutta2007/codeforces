#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, n, a[c], b[c], s[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> s[i];
        }
        int ert=0;
        for (int i=1; i<=n; i++) {
            ert+=a[i]-b[i-1]+s[i];
            if (i<n) {
                ert=max(b[i], ert+(b[i]-a[i]+1)/2);
            }
        }
        cout << ert << "\n";
    }
    return 0;
}
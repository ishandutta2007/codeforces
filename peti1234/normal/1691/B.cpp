#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, t[c], ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            ans[i]=i;
        }
        for (int i=1; i<n; i++) {
            if (t[i]==t[i+1]) {
                swap(ans[i], ans[i+1]);
            }
        }
        bool baj=0;
        for (int i=1; i<=n; i++) {
            if (ans[i]==i) {
                baj=1;
            }
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            for (int i=1; i<=n; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
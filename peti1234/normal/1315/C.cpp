#include <bits/stdc++.h>

using namespace std;
const int c=202;
int w, n, t[c], ans[c];
bool v[c], baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=2*n; i++) {
            v[i]=0, ans[i]=0;
        }
        baj=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            ans[2*i-1]=t[i];
            if (v[t[i]]) {
                baj=1;
            }
            v[t[i]]=1;
        }
        for (int i=1; i<=n; i++) {
            int ert=t[i];
            while (v[ert] && ert<=2*n) {
                ert++;
            }
            if (ert>2*n) {
                baj=1;
            }
            ans[2*i]=ert;
            v[ert]=1;
        }
        if (baj) {
            cout << -1 << "\n";
            continue;
        }
        for (int i=1; i<=2*n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
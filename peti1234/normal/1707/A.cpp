#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, p, t[c], ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> p;
        for (int i=1; i<=n; i++) cin >> t[i];
        int ert=0;
        for (int i=n; i>=1; i--) {
            if (ert>=t[i] || ert<p) {
                ans[i]=1;
                if (ert<t[i]) ert++;
            }
        }
        for (int i=1; i<=n; i++) cout << ans[i];
        cout << "\n";
        for (int i=1; i<=n; i++) ans[i]=0;
    }
    return 0;
}
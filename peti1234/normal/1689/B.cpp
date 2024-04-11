#include <bits/stdc++.h>

using namespace std;
int n, p[1005], ans[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    int w, n, m, k;
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> p[i];
            ans[i]=i;
        }
        if (n==1) {
            cout << -1 << "\n";
            continue;
        }
        for (int i=1; i<n; i++) {
            if (ans[i]==p[i]) {
                swap(ans[i], ans[i+1]);
            }
        }
        if (ans[n]==p[n]) {
            swap(ans[n], ans[n-1]);
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
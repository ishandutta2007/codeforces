#include <bits/stdc++.h>

using namespace std;
int n, m, k, t[105], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n*m; i++) {
        int x;
        cin >> x;
        for (int j=k; j>1; j--) {
            if (t[j]==x) {
                ans++;
                swap(t[j], t[j-1]);
            }
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
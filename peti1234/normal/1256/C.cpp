#include <bits/stdc++.h>

using namespace std;
int n, m, d, t[1005], ans[1005], sum, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> d;
    for (int i=1; i<=m; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    int dif=max(0, n+1-sum-d);
    if (dif>m*(d-1)) {
        cout << "NO\n";
        return 0;
    }
    sum=0;
    for (int i=1; i<=m; i++) {
        int mini=min(d-1, dif);
        dif-=mini, sum+=mini;
        while (t[i]--) {
            ans[++sum]=i;
        }
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
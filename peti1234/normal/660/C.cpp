#include <bits/stdc++.h>

using namespace std;
int n, k, ans, kezd, ert=1, db, t[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (!t[i]) db++;
        while (db>k) {
            if (!t[ert]) db--;
            ert++;
        }
        if (i-ert+1>ans) {
            ans=i-ert+1;
            kezd=ert;
        }
    }
    cout << ans << "\n";
    for (int i=1; i<=n; i++) {
        if (kezd<=i && i<kezd+ans) t[i]=1;
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}
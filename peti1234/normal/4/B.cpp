#include <bits/stdc++.h>

using namespace std;
int n, l[100], r[100], ans[100], sum, ert;
int main()
{
    cin >> n >> sum;
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i];
        ans[i]=l[i];
        ert+=l[i];
    }
    for (int i=1; i<=n; i++) {
        while (ert<sum && ans[i]<r[i]) {
            ans[i]++, ert++;
        }
    }
    if (ert!=sum) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
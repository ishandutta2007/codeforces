#include <bits/stdc++.h>

using namespace std;
int t[100002], n, mini=INT_MAX, r;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        mini=min(mini, t[i]);
    }
    for (int i=1; i<=n; i++) {
        if (t[i]%mini) r++;
    }
    if (r) cout << -1 << "\n";
    else cout << mini << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n, mini, maxi, ert;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        if (a[i]=='1' && b[i]=='0') ert++, maxi=max(maxi, ert);
        if (a[i]=='0' && b[i]=='1') ert--, mini=min(mini, ert);
    }
    if (ert) cout << -1 << "\n";
    else cout << maxi-mini << "\n";
    return 0;
}
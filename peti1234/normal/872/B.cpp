#include <bits/stdc++.h>

using namespace std;
int n, k, mini=1e9, maxi=-1e9, t[100002];
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        mini=min(mini, t[i]);
        maxi=max(maxi, t[i]);
    }
    if (k==1) cout << mini << "\n";
    if (k==2) cout << max(t[1], t[n]) << "\n";
    if (k>=3) cout << maxi << "\n";
    return 0;
}
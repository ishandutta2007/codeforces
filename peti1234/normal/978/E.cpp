#include <bits/stdc++.h>

using namespace std;
int n, m, sum, x, mini, maxi;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> x;
        sum+=x;
        mini=min(mini, sum);
        maxi=max(maxi, sum);
    }
    cout << max(0, m+mini-maxi+1) << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
long long maxi, n, t[502];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    if (n==1) cout << t[1];
    else if (n==2) cout << (t[1]|t[2]);
    else {
        for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) for (int k=j+1; k<=n; k++) maxi=max(maxi, (t[i]|t[j]|t[k]));
        cout << maxi;
    }
    return 0;
}
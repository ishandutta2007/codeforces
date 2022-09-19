#include <bits/stdc++.h>

using namespace std;
int n, t[200005], mini=2e9, db;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    for (int i=2; i<=n; i++) {
        if (t[i]-t[i-1]<mini) mini=t[i]-t[i-1], db=0;
        if (t[i]-t[i-1]==mini) db++;
    }
    cout << mini << " " << db << "\n";
    return 0;
}
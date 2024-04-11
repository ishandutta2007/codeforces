#include <bits/stdc++.h>

using namespace std;
int n, t[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    int ans=0;
    for (int i=2; i<=n; i+=2) {
        ans+=t[i]-t[i-1];
    }
    cout << ans << "\n";
    return 0;
}
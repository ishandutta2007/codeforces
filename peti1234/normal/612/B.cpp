#include <bits/stdc++.h>

using namespace std;
int n, inv[200005];
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        inv[x]=i;
    }
    for (int i=1; i<n; i++) {
        ans+=abs(inv[i+1]-inv[i]);
    }
    cout << ans << "\n";
    return 0;
}
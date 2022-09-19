#include <bits/stdc++.h>

using namespace std;
int n, q, ans, t[102], kom[102];
int main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        kom[i]=kom[i-1]+t[i];
    }
    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        ans+=max(0, kom[b]-kom[a-1]);
    }
    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w, n, x, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            ans|=x;
        }
        cout << ans << "\n";
    }
    return 0;
}
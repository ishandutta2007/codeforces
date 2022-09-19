#include <bits/stdc++.h>

using namespace std;
int w, n, sum, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sum=0, ans=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (!x) {
                ans++, x++;
            }
            sum+=x;
        }
        if (!sum) {
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
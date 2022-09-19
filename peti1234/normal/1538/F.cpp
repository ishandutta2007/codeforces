#include <bits/stdc++.h>

using namespace std;
int w, l, r, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> l >> r;
        ans=0;
        while (r) {
            ans+=r-l;
            l/=10, r/=10;
        }
        cout << ans << "\n";
    }
    return 0;
}
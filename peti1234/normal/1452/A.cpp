#include <bits/stdc++.h>

using namespace std;
int w, x, y;
int main()
{
    cin >> w;
    while(w--) {
        cin >> x >> y;
        int ans=2*max(x, y);
        if (x!=y) ans--;
        cout << ans << "\n";
    }
    return 0;
}
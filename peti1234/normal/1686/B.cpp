#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, ans=0, ut=0;
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if (x<ut) {
                ans++, ut=0;
            } else {
                ut=x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
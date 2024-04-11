#include <bits/stdc++.h>

using namespace std;
int w, n, ans;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> ans;
        for (int i=1; i<n; i++) {
            int x;
            cin >> x;
            ans=(ans&x);
        }
        cout << ans << "\n";
    }
    return 0;
}
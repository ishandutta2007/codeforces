#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        int jo=1, el=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (el>x) jo=0;
            el=x;
        }
        cout << (jo ? "NO" : "YES") << "\n";
    }
    return 0;
}
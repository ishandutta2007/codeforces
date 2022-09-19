#include <bits/stdc++.h>

using namespace std;
int w, n, t[55];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        bool jo=1;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (i>2 && (t[i]+t[i-2])%2) jo=0;
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, el=0, x;
        cin >> n;
        bool jo=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (x<=el) jo=1;
            el=x;
        }
        if (n%2==0 || jo) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
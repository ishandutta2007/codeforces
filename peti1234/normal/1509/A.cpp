#include <bits/stdc++.h>

using namespace std;
int w, n, t[2002];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            if (t[i]%2) {
                cout << t[i] << " ";
            }
        }
        for (int i=1; i<=n; i++) {
            if (t[i]%2==0) {
                cout << t[i] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
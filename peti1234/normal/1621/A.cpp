#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n, k;
    cin >> w;
    while (w--) {
        cin >> n >> k;
        if (k>(n+1)/2) cout << -1 << "\n";
        else {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    cout << (i==j && i%2 && i<=2*k ? "R" : ".");
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
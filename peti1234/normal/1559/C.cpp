#include <bits/stdc++.h>

using namespace std;
const int c=10005;
int w, n, t[c];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        if (t[1]==1) {
            cout << n+1 << " ";
            for (int i=1; i<=n; i++) {
                cout << i << " ";
            }
            cout << "\n";
        } else if (t[n]==0) {
            for (int i=1; i<=n+1; i++) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            for (int i=2; i<=n; i++) {
                if (t[i]==1 && t[i-1]==0) {
                    for (int j=1; j<i; j++) {
                        cout << j << " ";
                    }
                    cout << n+1 << " ";
                    for (int j=i; j<=n; j++) {
                        cout << j << " ";
                    }
                    cout << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
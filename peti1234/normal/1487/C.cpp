#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                int dif=2*(j-i);
                if (dif<n) {
                    cout << -1 << " ";
                }
                if (dif==n) {
                    cout << 0 << " ";
                }
                if (dif>n) {
                    cout << 1 << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
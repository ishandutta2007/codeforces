#include <bits/stdc++.h>

using namespace std;
int w, n, t[302];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            if (i%2) {
                cout << t[(i+1)/2] << " ";
            } else {
                cout << t[n+1-i/2] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
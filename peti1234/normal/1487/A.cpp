#include <bits/stdc++.h>

using namespace std;
int w, n, mini, mindb;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n, mini=1e9;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (x<mini) {
                mini=x, mindb=0;
            }
            if (x==mini) {
                mindb++;
            }
        }
        cout << n-mindb << "\n";
    }
    return 0;
}
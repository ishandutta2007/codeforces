#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, t[c], ert=1000000007;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        cout << n/2 << "\n";
        for (int i=2; i<=n; i+=2) {
            cout << i-1 << " " << i << " " << min(t[i-1], t[i]) << " " << ert << "\n";
        }
    }
    return 0;
}
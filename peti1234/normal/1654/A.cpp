#include <bits/stdc++.h>

using namespace std;
int w, n, t[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        cout << t[n-1]+t[n] << "\n";
    }
    return 0;
}
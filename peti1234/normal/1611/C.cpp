#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        if (t[1]!=n && t[n]!=n) cout << -1 << "\n";
        else {
            if (t[1]==n) reverse(t+2, t+n+1);
            else reverse(t+1, t+n);
            for (int i=1; i<=n; i++) cout << t[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}
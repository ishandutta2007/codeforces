#include <bits/stdc++.h>

using namespace std;
int n, w, t[200005];
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
        int cnt=0, f=n/2;
        for (int i=1; i<=n; i++) {
            if (t[i]==t[f]) cnt++;
        }
        if (n%2 || 2*cnt>=n && t[f]==t[f+1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=1; i<=f; i++) {
                cout << t[i] << " " << t[i+f] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        bool jo=1;
        for (int i=n; i>1; i-=2) {
            if (t[i]<t[i-1]) swap(t[i], t[i-1]);
        }
        cout << (is_sorted(t+1, t+n+1) ? "YES" : "NO") << "\n";
    }
    return 0;
}
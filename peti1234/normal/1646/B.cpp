#include <bits/stdc++.h>

using namespace std;
long long w, sa, sb, n, t[200005];
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
        for (int i=1; i<=n; i++) {
            if (i<=(n+1)/2) sa+=t[i];
            if (2*(i-1)>n) sb+=t[i];
        }
        cout << (sb>sa ? "YES" : "NO") << "\n";
        sa=0, sb=0;
    }
    return 0;
}
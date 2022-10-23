#include <bits/stdc++.h>

using namespace std;
int n, t[200005];
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    int pos=1, f=t[1]%2;
    for (int i=1; i<=n; i++) {
        if (f==t[i]%2) pos=i;
    }
    cout << n-1 << "\n";
    for (int i=1; i<pos; i++) {
        if (t[i]%2==f) cout << i << " " << pos << "\n";
    }
    for (int i=2; i<=n; i++) {
        if (t[i]%2!=f) {
            cout << 1 << " " << i << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
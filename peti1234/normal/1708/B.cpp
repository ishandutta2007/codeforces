#include <bits/stdc++.h>
 
using namespace std;
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    bool jo=1;
    for (int i=1; i<=n; i++) {
        int x=r/i*i;
        if (x<l) jo=0;
    }

    cout << (jo ? "YES" : "NO") << "\n";
if (jo) {
for (int i=1; i<=n; i++) {
        int x=r/i*i;
        cout << x << " ";
    }
cout << endl;
}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
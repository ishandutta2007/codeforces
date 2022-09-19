#include <bits/stdc++.h>
 
using namespace std;
void solve() {
    int n, x;
    cin >> n >> x;
    bool jo=1;
    for (int i=1; i<n; i++) {
        int s;
        cin >> s;
        if (s%x) jo=0;
    }
    cout << (jo ? "YES" : "NO") << "\n";
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
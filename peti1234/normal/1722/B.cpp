#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    bool jo=1;
    for (int i=0; i<n; i++) {
        if ((a[i]=='R') != (b[i]=='R')) jo=0;
    }
    cout << (jo ? "YES" : "NO") << "\n";
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
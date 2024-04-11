#include <bits/stdc++.h>

using namespace std;
void solve() {
    string a="Timur", b;
    int x;
    cin >> x;
    cin >> b;
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    cout << (a==b ? "YES" : "NO") << "\n";
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
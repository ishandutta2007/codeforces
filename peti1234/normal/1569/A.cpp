#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
void solve() {
    cin >> n >> s;
    for (int i=0; i<n-1; i++) {
        if (s[i]!=s[i+1]) {
            cout << i+1 << " " << i+2 << "\n";
            return;
        }
    }
    cout << -1 << " " << -1 << "\n";
    return;
}
int main()
{
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
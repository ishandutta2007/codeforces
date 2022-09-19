#include <bits/stdc++.h>

using namespace std;
void solve() {
    int maxi=0;
    map<char, int> m;
    for (int i=0; i<4; i++) {
        char c;
        cin >> c;
        maxi=max(maxi, ++m[c]);
    }
    int si=m.size();
    cout << si-1 << "\n";
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
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, z, maxi=0, x;
    cin >> n >> z;
    while (n--) {
        cin >> x;
        maxi=max(maxi, x|z);
    }
    cout << maxi << "\n";
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
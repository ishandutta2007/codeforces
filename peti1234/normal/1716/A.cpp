#include <bits/stdc++.h>

using namespace std;
void solve() {
    int x;
    cin >> x;
    cout << (x==1 ? 2 : (x+2)/3) << "\n";
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
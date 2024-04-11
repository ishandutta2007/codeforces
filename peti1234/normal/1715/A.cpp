#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    if (n==1 && m==1) {
        cout << 0 << "\n";
        return;
    }
    cout << n-1+m-1+1+min(n-1, m-1) << "\n";
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
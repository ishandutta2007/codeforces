#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, mini=2e9, pos=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x<mini) {
            mini=x;
            pos=i;
        }
    }
    if (n%2 || pos%2==0) {
        cout << "Mike\n";
    } else {
        cout << "Joe\n";
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
#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, k=0;
    cin >> n;
    if (n==1) {
        cout << k << "\n";
    } else if (n==2) {
        cout << 0 << " " << k << "\n";
    } else {
        for (int i=0; i<n-3; i++) {
            cout << i << " ";
            k^=i;
        }
        int a=(1<<19), b=(1<<20);
        cout << a << " " << b << " " << (a^b^k) << "\n";
    }
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
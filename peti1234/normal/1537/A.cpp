#include <bits/stdc++.h>

using namespace std;
int w, n, sum, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sum=0;
        for (int i=1; i<=n; i++) {
            cin >> x;
            sum+=x;
        }
        if (sum<n) {
            cout << 1 << "\n";
        }
        if (sum==n) {
            cout << 0 << "\n";
        }
        if (sum>n) {
            cout << sum-n << "\n";
        }
    }
    return 0;
}
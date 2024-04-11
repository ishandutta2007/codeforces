#include <bits/stdc++.h>

using namespace std;
int n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (k>=(n*(n-1))/2) {
        cout << "no solution\n";
    } else {
        for (int i=1; i<=n; i++) {
            cout << 0 << " " << i << "\n";
        }
    }
    return 0;
}
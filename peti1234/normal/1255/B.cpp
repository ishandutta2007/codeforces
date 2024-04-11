#include <bits/stdc++.h>

using namespace std;
int w, n, m;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> m;
        int sum=0;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sum+=2*x;
        }
        if (n>2 && n==m) {
            cout << sum << "\n";
            for (int i=1; i<n; i++) {
                cout << i << " " << i+1 << "\n";
            }
            cout << n << " " << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
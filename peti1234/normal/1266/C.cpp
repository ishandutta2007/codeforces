#include <bits/stdc++.h>

using namespace std;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n==1 && m==1) {
        cout << 0 << "\n";
        return 0;
    }
    if (m==1) {
        for (int i=1; i<=n; i++) {
            cout << i+1 << "\n";
        }
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=n+1; j<=n+m; j++) {
            cout << i*j << " ";
        }
        cout << "\n";
    }
    return 0;
}
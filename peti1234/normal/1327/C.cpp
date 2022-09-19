#include <bits/stdc++.h>

using namespace std;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cout << n+m+n*m-3 << "\n";
    for (int i=1; i<n; i++) cout << 'U';
    for (int i=1; i<m; i++) cout << 'L';
    for (int i=1; i<=n; i++) {
        for (int j=1; j<m; j++) {
            if (i%2) cout << 'R';
            else cout << 'L';
        }
        if (i!=n) cout << 'D';
    }
    return 0;
}
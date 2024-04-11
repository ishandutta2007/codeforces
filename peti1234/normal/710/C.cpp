#include <bits/stdc++.h>

using namespace std;
int ans[50][50], n, a, b;
int main()
{
    cin >> n;
    a=0, b=n/2;
    for (int i=1; i<=n*n; i++) {
        ans[a][b]=i;
        if (i%n) {
            a=(a+n-1)%n;
            b=(b+1)%n;
        } else {
            a=(a+1)%n;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
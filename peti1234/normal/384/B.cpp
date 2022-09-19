#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    cout << m*(m-1)/2 << "\n";
    for (int i=1; i<=m; i++) {
        for (int j=i+1; j<=m; j++) {
            if (k==0) cout << i << " "  << j << "\n";
            else cout << j << " " << i << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=min(2*n, m); i++) {
        if (i+2*n<=m) cout << i+2*n << " ";
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
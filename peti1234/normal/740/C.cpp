#include <bits/stdc++.h>

using namespace std;
int n, m, valasz=1e9;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        valasz=min(valasz, r-l+1);
    }
    cout << valasz << "\n";
    for (int i=1; i<=n; i++) {
        cout << i%valasz << " ";
    }
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long x;
        cin >> x;
        if (x%2) cout << -1 << "\n";
        else cout << 0 << " " << 0 << " " << x/2 << "\n";
    }
    return 0;
}
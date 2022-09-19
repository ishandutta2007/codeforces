#include <bits/stdc++.h>

using namespace std;
long long w, x, y, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> x >> y >> k;
        cout << (x*y==k+1 ? "YES" : "NO") << "\n";
    }
    return 0;
}
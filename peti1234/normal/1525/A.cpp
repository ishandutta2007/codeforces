#include <bits/stdc++.h>

using namespace std;
int w, n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cout << 100/__gcd(100, n) << "\n";
    }
    return 0;
}
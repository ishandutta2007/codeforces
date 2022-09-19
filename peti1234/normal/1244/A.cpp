#include <bits/stdc++.h>

using namespace std;
long long w, a, b, c, d, k;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> c >> d >> k;
        if ((a+c-1)/c+(b+d-1)/d>k) {
            cout << -1 << "\n";
        } else {
            cout << (a+c-1)/c << " " << (b+d-1)/d << "\n";
        }
    }
    return 0;
}
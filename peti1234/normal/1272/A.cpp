#include <bits/stdc++.h>

using namespace std;
int w, a, b, c, tav;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> c;
        tav=max({abs(a-b), abs(a-c), abs(b-c)});
        cout << 2*max(0, tav-2) << "\n";
    }
    return 0;
}
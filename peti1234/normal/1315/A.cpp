#include <bits/stdc++.h>

using namespace std;
int w, a, b, x, y;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> x >> y;
        cout << max({x*b, (a-x-1)*b, y*a, (b-y-1)*a}) << "\n";
    }
    return 0;
}
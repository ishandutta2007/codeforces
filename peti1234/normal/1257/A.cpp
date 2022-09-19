#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << min(a-1, abs(c-d)+b) << "\n";
    }
    return 0;
}
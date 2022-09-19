#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (max(a, c)<=min(b, d) ? max(a, c) : a+c) << "\n";
    }
    return 0;
}
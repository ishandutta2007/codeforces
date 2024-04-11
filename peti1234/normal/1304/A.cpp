#include <bits/stdc++.h>

using namespace std;
int w, x, y, a, b, z, c;
int main()
{
    cin >> w;
    while (w--) {
        cin >> x >> y >> a >> b, z=abs(x-y), c=a+b;
        cout << (z%c? -1 : z/c) << "\n";
    }
    return 0;
}
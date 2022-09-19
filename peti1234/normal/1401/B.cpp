#include <bits/stdc++.h>

using namespace std;
int w, a, b, c, d, e, f, g;
int main()
{
    cin >> w;
    while(w--) {
        cin >> a >> b >> c >> d >> e >> f, g=min(c, e);
        cout << 2*g-max(0, b+f-a-c-d-e+2*g) << "\n";
    }
    return 0;
}
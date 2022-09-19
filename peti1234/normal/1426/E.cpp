#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, e, f, n;
int main()
{
    cin >> n >> a >> b >> c >> d >> e >> f;
    cout << max({0, a+e-n, b+f-n, c+d-n}) << " ";
    cout << min(a, e)+min(b, f)+min(c, d) << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        cout << (a+c>=x && b+c>=y && a+b+c>=x+y ? "YES" : "NO") << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
long long a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    cout << (a+b)/c << " ";
    if (a%c+b%c>=c) {
        cout << min(c-a%c, c-b%c) << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}
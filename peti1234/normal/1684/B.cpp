#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << a+b+c << " " << b+c << " " << c << "\n";
    }
    return 0;
}
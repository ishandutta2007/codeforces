#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        if (b%a) cout << 0 << " " << 0 << "\n";
        else cout << 1 << " " << b/a << "\n";
    }
    return 0;
}
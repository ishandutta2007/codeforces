#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (b>a)+(c>a)+(d>a) << "\n";
    }
    return 0;
}
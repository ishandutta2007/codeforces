#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, a, b, c, s;
    cin >> w;
    while (w--) {
        cin >> a >> b >> c;
        s=a+b+c;
        cout << (s%3 ? 1 : 0) << "\n";
    }
    return 0;
}
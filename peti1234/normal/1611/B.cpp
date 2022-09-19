#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, a, b;
    cin >> w;
    while (w--) {
        cin >> a >> b;
        if (a>b) swap(a, b);
        cout << min(a, (a+b)/4) << "\n";
    }
    return 0;
}
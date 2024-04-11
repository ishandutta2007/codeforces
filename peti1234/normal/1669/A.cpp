#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int x;
        cin >> x;
        cout << "Division ";
        if (x>=1900) cout << 1;
        else if (x>=1600) cout << 2;
        else if (x>=1400) cout << 3;
        else cout << 4;
        cout << "\n";
    }
    return 0;
}
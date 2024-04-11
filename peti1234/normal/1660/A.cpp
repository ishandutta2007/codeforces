#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        if (a==0) cout << 1 << "\n";
        else cout << a+2*b+1 << "\n";
    }
    return 0;
}
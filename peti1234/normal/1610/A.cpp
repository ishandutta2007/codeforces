#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, a, b;
    cin >> w;
    while (w--) {
        cin >> a >> b;
        cout << 2-(a==1)-(b==1) << "\n";
    }
    return 0;
}
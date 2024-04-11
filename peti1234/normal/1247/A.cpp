#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (b==a+1) {
        cout << a << " " << b << "\n";
    } else if (a==b) {
        cout << a << 0 << " " << b << 1 << "\n";
    } else if (a==9 && b==1) {
        cout << 9 << " " << 10 << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
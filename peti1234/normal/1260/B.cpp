#include <bits/stdc++.h>

using namespace std;
int w, a, b;
int main()
{
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        if ((a+b)%3 || a>2*b || b>2*a) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
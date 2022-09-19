#include <bits/stdc++.h>

using namespace std;
int w, a, b, c;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> c;
        int h=abs(a-b);
        if (max({a, b, c})>2*h) {
            cout << -1 << "\n";
        } else {
            cout << (c>h ? c-h : c+h) << "\n";
        }
    }
    return 0;
}
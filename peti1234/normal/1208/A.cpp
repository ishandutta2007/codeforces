#include <bits/stdc++.h>

using namespace std;
int w, a, b, x;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> x;
        if (x%3==0) {
            cout << a;
        }
        if (x%3==1) {
            cout << b;
        }
        if (x%3==2) {
            cout << (a^b);
        }
        cout << "\n";
    }
    return 0;
}
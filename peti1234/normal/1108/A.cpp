#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << a << " ";
        if (d==a) {
            cout << d-1;
        } else {
            cout << d;
        }
        cout << endl;
    }
    return 0;
}
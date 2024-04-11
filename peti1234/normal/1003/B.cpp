#include <bits/stdc++.h>

using namespace std;
int a, b, x, el;
int main()
{
    cin >> a >> b >> x;
    if (a>b) {
        cout << 0;
        a--;
    } else {
        cout << 1;
        b--;
        el=1;
    }
    while (a>0 && b>0) {
        if (x>1) {
            if (el==0) {
                cout << 1;
                b--;
                el=1;
            } else {
                cout << 0;
                a--;
                el=0;
            }
            x--;
        } else {
            cout << el;
            if (el==0) a--;
            else b--;
        }
    }
    for (int i=0; i<a; i++) cout << 0;
    for (int i=0; i<b; i++) cout << 1;
    return 0;
}
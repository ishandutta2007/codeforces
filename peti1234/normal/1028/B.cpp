#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i=1; i<=500; i++) {
        if (i%2==0) {
            cout << 4;
        } else {
            cout << 5;
        }
    }
    cout << 5 << endl;
    for (int i=1; i<=500; i++) {
        if (i%2!=0) {
            cout << 4;
        } else {
            cout << 5;
        }
    }
    cout << 5 << endl;
    return 0;
}
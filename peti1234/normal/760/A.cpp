#include <bits/stdc++.h>

using namespace std;
int h, n;
int main()
{
    cin >> h >> n;
    if (h==2) {
        if (n==1) {
            cout << 4 << endl;
            return 0;
        }
        else {
            cout << 5 << endl;
            return 0;
        }
    }
    if (h==4) {
        if (n==7) {
            cout << 6 << endl;
            return 0;
        }
        else {
            cout << 5 << endl;
            return 0;
        }
    }
    if (h==6) {
        if (n==7) {
            cout << 6 << endl;
            return 0;
        }
        else {
            cout << 5 << endl;
            return 0;
        }
    }
    if (h==9) {
        if (n==7) {
            cout << 6 << endl;
            return 0;
        }
        else {
            cout << 5 << endl;
            return 0;
        }
    }
    if (h==11) {
        if (n==7) {
            cout << 6 << endl;
            return 0;
        }
        else {
            cout << 5 << endl;
            return 0;
        }
    }
    if (n==6) {
        cout << 6 << endl;
        return 0;
    }
    if (n==7) {
        cout << 6 << endl;
         return 0;
    }
    cout << 5 << endl;
    return 0;
}
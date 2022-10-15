#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll a00, a01, a10, a11;

void lol(ll u0, ll u1) {
    ll u01 = 0;
    ll u10 = 0;
    string s;
    while (u0*(u0-1)/2 < a00) u0++;
    while (u1*(u1-1)/2 < a11) u1++;
    if (u0*(u0-1)/2 != a00 || u1*(u1-1)/2 != a11) {
        return;
    }
    u01 = u0*u1;
    int x = u0;
    int y = u1;
    while (u01 > a01) {
        if (u01-a01 >= x) {
            u01 -= x;
            u10 += x;
            s += "1";
            y--;
        } else {
            x--;
            s += "0";
        }
    }
    if (u01 != a01 || u10 != a10 || x < 0 || y < 0) {
        return;
    }
    while (x) {s += "0"; x--;}
    while (y) {s += "1"; y--;}
    cout << s << "\n";
    exit(0);
}

int main() {
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00 == 0 && a11 == 0 && a01 == 0 && a10 == 0) {
        cout << "0\n";
        return 0;
    }
    if (a00 == 0 && a11 == 0 && a01 == 1 && a10 == 0) {
        cout << "01\n";
        return 0;
    }
    if (a00 == 0 && a11 == 0 && a01 == 0 && a10 == 1) {
        cout << "10\n";
        return 0;
    }
    lol(0,0);
    lol(0,1);
    lol(1,0);
    lol(1,1);
    cout << "Impossible\n";
}
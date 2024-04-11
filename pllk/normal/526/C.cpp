#include <iostream>

using namespace std;

#define ll long long

ll c, hr, hb, wr, wb;

int main() {
    cin >> c >> hr >> hb >> wr >> wb;
    if (wr >= 1000) {
        ll t = 0;
        for (int r = 0; r*wr <= c; r++) {
            ll u = r*hr;
            ll z = c-r*wr;
            u += (z/wb)*hb;
            t = max(t, u);
        }
        cout << t << "\n";
    } else if (wb >= 1000) {
        ll t = 0;
        for (int b = 0; b*wb <= c; b++) {
            ll u = b*hb;
            ll z = c-b*wb;
            u += (z/wr)*hr;
            t = max(t, u);
        }
        cout << t << "\n";
    } else {
        ll t = 0;
        for (int r = 0; r*wr <= c && r <= 1000; r++) {
            ll u = r*hr;
            ll z = c-r*wr;
            u += (z/wb)*hb;
            t = max(t, u);
        }
        for (int b = 0; b*wb <= c && b <= 1000; b++) {
            ll u = b*hb;
            ll z = c-b*wb;
            u += (z/wr)*hr;
            t = max(t, u);
        }
        cout << t << "\n";
    }
}
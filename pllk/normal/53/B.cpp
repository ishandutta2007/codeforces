#include <iostream>

using namespace std;

#define ll long long

ll h, w;
ll uh, uw;
ll s = 0, s2 = 0;

void pysty(int q) {
    if (q > h) return;
    if ((double)q/w > 1.25) return;
    ll t = 0;
    for (ll b = w; b >= 1; b /= 2) {
        while (t+b <= w && (double)q/(t+b) >= 0.799999999) t += b;
    }
    if (t*q > s) {
        s = t*q;
        uh = q;
        uw = t;
    } else if (t*q == s && q > s2) {
        s2 = q;
        uh = q;
        uw = t;
    }
}

void vaaka(int q) {
    if (q > w) return;
    if ((double)h/q < 0.8) return;
    ll t = 0;
    for (ll b = h; b >= 1; b /= 2) {
        while (t+b <= h && (double)(t+b)/q <= 1.250000001) t += b;
    }
    //cout << "l " << q << " " << t+1 << " " << ((t+1)/q <= 1.25) << endl;
    if (t*q > s) {
        s = t*q;
        uh = t;
        uw = q;
    } else if (t*q == s && t > s2) {
        s2 = t;
        uh = t;
        uw = q;
    }
}

int main() {
    cin >> h >> w;
    for (int i = 0; i <= 30; i++) {
        pysty(1<<i);
        vaaka(1<<i);
    }
    cout << uh << " " << uw << endl;
}
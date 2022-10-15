#include <iostream>

using namespace std;

string a, b, c;
int z[128];
int z1[128], z2[128];
int u[128];
int p, px, py;

int main() {
    cin >> a >> b >> c;
    for (int i = 0; i < a.size(); i++) z[a[i]]++;
    for (int i = 0; i < b.size(); i++) z1[b[i]]++;
    for (int i = 0; i < c.size(); i++) z2[c[i]]++;
    int x = 0, y = 0;
    while (true) {
        bool ok = true;
        for (int i = 'a'; i <= 'z'; i++) {
            if (u[i]+z1[i] > z[i]) ok = false;
        }
        if (!ok) break;
        x++;
        for (int i = 'a'; i <= 'z'; i++) {
            u[i] += z1[i];
        }
    }
    p = x;
    px = x;
    py = 0;
    while (true) {
        while (true) {
            bool ok = true;
            for (int i = 'a'; i <= 'z'; i++) {
                if (u[i]+z2[i] > z[i]) ok = false;
            }
            if (!ok) break;
            y++;
            for (int i = 'a'; i <= 'z'; i++) {
                u[i] += z2[i];
            }
        }
        if (x+y > p) {
            p = x+y;
            px = x;
            py = y;
        }
        if (x == 0) break;
        x--;
        for (int i = 'a'; i <= 'z'; i++) {
            u[i] -= z1[i];
        }
    }
    for (int i = 0; i < px; i++) cout << b;
    for (int i = 0; i < py; i++) cout << c;
    for (int i = 0; i < px; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            z[j] -= z1[j];
        }
    }
    for (int i = 0; i < py; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            z[j] -= z2[j];
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 0; j < z[i]; j++) {
            cout << (char)i;
        }
    }
    cout << "\n";
}
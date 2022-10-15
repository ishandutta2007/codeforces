#include <iostream>

using namespace std;

int n;
int c[202020];
int d[202020];

int main() {
    cin >> n;
    int u = 0;
    int z = -999999999;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
        if (d[i] == 2) z = max(z,u);
        u += c[i];
    }
    if (z == -999999999) {
        cout << "Infinity\n";
        return 0;
    }
    u = 1899-z;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1 && u < 1900) {
            cout << "Impossible\n";
            return 0;
        }
        if (d[i] == 2 && u >= 1900) {
            cout << "Impossible\n";
            return 0;
        }
        u += c[i];
    }
    cout << u << "\n";
}
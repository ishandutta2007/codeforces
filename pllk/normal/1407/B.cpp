#include <iostream>

using namespace std;

int a[1111];

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int g = 0;
        for (int i = 1; i <= n; i++) {
            int ug = 0, ui;
            for (int j = 1; j <= n; j++) {
                if (a[j] != 0 && gcd(g,a[j]) > ug) {
                    ug = gcd(g,a[j]);
                    ui = j;
                }
            }
            cout << a[ui] << " ";
            a[ui] = 0;
            g = ug;
        }
        cout << "\n";
    }
}
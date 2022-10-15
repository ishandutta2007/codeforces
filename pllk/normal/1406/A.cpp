#include <iostream>

using namespace std;

int c[200];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 200; i++) c[i] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            c[x]++;
        }
        int a = 0;
        for (int i = 0; ; i++) {
            if (c[i]) {
                c[i]--;
                a++;
            } else break;
        }
        int b = 0;
        for (int i = 0; ; i++) {
            if (c[i]) {
                c[i]--;
                b++;
            } else break;
        }
        cout << a+b << "\n";
    }
}
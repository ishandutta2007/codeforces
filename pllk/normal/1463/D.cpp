#include <iostream>

using namespace std;

int b[404040];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2*n; i++) b[i] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            b[x] = 1;
        }
        int c = 0;
        int u1 = 0;
        for (int i = 1; i <= 2*n; i++) {
            if (b[i] == 0) c++;
            else if (c > 0) {u1++; c--;}
        }
        c = 0;
        int u2 = 0;
        for (int i = 2*n; i >= 1; i--) {
            if (b[i] == 0) c++;
            else if (c > 0) {u2++; c--;}
        }
        cout << u2-n+u1+1 << "\n";
    }
}
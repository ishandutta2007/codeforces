#include <iostream>

using namespace std;

int n;

bool ok(int x) {
    if (x == 1) return false;
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    if (ok(n)) {
        cout << "1\n" << n << "\n";
        return 0;
    }
    for (int i = n-1; ; i--) {
        if (!ok(i)) continue;
        int u = n-i;
        if (ok(u)) {
            cout << "2\n" << u << " " << i << "\n";
            return 0;
        }
        for (int j = 2; j <= u-2; j++) {
            if (ok(j) && ok(u-j)) {
                cout << "3\n" << i << " " << j << " " << u-j << "\n";
                return 0;
            }
        }
    }
}
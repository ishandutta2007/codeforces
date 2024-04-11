#include <iostream>

using namespace std;

bool prime(int n) {
    for (int i = 2; i <= n-1; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = n;
        while (!prime(x) || prime(x-n+1)) x++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) cout << x-n+1 << " ";
                else cout << 1 << " ";
            }
            cout << "\n";
        }
    }
}
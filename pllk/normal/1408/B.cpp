#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int c = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i-1]) c++;
        }
        if (k == 1) {
            if (c == 1) cout << "1\n";
            else cout << "-1\n";
        } else {
            c -= k;
            int h = 1;
            while (c > 0) {
                c -= (k-1);
                h++;
            }
            cout << h << "\n";
        }
    }
}
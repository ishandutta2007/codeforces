#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= 2*n; i++) {
            int x;
            cin >> x;
            if (x%2 == 0) c1++;
            else c2++;
        }
        if (c1 == c2) cout << "YES\n";
        else cout << "NO\n";
    }
}
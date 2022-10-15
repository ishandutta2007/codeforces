#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n%2 == 1) {
            cout << "Bob\n";
        } else {
            int x = 1;
            int f = 0;
            int c = 0;
            while (x <= 1e9) {
                if (x == n && c%2 == 1) f = 1;
                x *= 2;
                c++;
            }
            if (f) cout << "Bob\n";
            else cout << "Alice\n";
        }
    }
}
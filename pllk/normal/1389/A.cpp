#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a*2 <= b) {
            cout << a << " " << a*2 << "\n";
        } else {
            cout << -1 << " " << -1 << "\n";
        }
    }
}
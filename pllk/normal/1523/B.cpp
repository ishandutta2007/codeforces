#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x;
        for (int i = 1; i <= n; i++) cin >> x;
        cout << (n/2)*6 << "\n";
        for (int i = 1; i <= n; i += 2) {
            cout << "2 " << i << " " << i+1 << "\n";
            cout << "1 " << i << " " << i+1 << "\n";
            cout << "2 " << i << " " << i+1 << "\n";
            cout << "1 " << i << " " << i+1 << "\n";
            cout << "2 " << i << " " << i+1 << "\n";
            cout << "1 " << i << " " << i+1 << "\n";
        }
    }
}
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int r = (n+3)/4;
        for (int i = 1; i <= n-r; i++) cout << "9";
        for (int i = 1; i <= r; i++) cout << "8";
        cout << "\n";
    }
}
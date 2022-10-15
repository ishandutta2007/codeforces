#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    if (n == 1 || n == 2) {
        cout << "1\n";
        cout << "1\n";
        return 0;
    }
    if (n == 3) {
        cout << "2\n";
        cout << "1 3\n";
        return 0;
    }
    if (n == 4) {
        cout << "4\n";
        cout << "2 4 1 3\n";
        return 0;
    }
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        if (i%2 == 0) cout << i/2+1 << " ";
        else cout << n/2+1+n%2+i/2 << " ";
    }
    cout << "\n";
}
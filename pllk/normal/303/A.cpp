#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    if (n == 1) {
        cout << 0 << endl << 0 << endl << 0 << endl;
        return 0;
    }
    if (n%2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << (i+1)%n << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << (i+i+1)%n << " ";
    }
    cout << endl;
}
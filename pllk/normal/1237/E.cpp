#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << "1\n";
        return 0;
    } else if (n == 3) {
        cout << "0\n";
        return 0;
    } else if (n == 4 || n == 5) {
        cout << "1\n";
        return 0;
    }
    int a = 4;
    int b = 9;
    while (b <= n) {
        if (b == n || b+1 == n) {
            cout << "1\n";
            return 0;
        }
        int c = b;
        b = 2*b+1;
        if (a%2 == 0) b++;
        a = c;
    }
    cout << "0\n";
}
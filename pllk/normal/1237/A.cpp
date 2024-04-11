#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x%2 == 0) {
            cout << x/2 << "\n";
        } else {
            if (a == 0) {
                if (x >= 0) {
                    cout << x/2+1 << "\n";
                } else {
                    cout << x/2 << "\n";
                }
            } else {
                if (x >= 0) {
                    cout << x/2 << "\n";
                } else {
                    cout << x/2-1 << "\n";
                }
            }
            a = 1-a;
        }
    }
}
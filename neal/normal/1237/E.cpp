#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int odd = 1, even = 2;

    while (min(odd, even) <= n) {
        if (n == odd || n == even) {
            cout << 1 << '\n';
            return 0;
        }

        int new_odd = even + even + 1;
        int new_even = odd + even + 1;
        odd = new_odd;
        even = new_even;
    }

    cout << 0 << '\n';
}
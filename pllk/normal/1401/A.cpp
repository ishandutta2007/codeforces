#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int r = 0;
        if (n%2 != k%2) {n++; r++;}
        if (n < k) r += k-n;
        cout << r << "\n";
    }
}
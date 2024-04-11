#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s += x;
        }
        if (s >= n) cout << s-n << "\n";
        else cout << "1\n";
    }
}
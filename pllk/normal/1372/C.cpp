#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int t = 0;
        int c = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == i) {
                t = 0;
            } else {
                if (t == 0) c++;
                t = 1;
            }
        }
        if (c == 0) cout << "0\n";
        else if (c == 1) cout << "1\n";
        else cout << "2\n";
    }
}
#include <iostream>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    if (k == 1) {
        if (n == 1) cout << 'a' << endl;
        else cout << -1 << endl;
        return 0;
    }
    if (k > n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (n-i > k-2) {
            if (i%2 == 0) cout << 'a';
            if (i%2 == 1) cout << 'b';
        } else {
            char m = 'b'+(k-(n-i+1));
            cout << m;
        }
    }
    cout << endl;
}
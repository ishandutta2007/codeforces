#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1) cout << "0\n";
        else if (n == 1 || m == 1) cout << "1\n";
        else cout << "2\n";
    }
}
#include <iostream>

using namespace std;

int n;
int x[111];
int s;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        s += x[i];
    }
    if (s != 0) {
        cout << "YES\n";
        cout << "1\n";
        cout << "1 " << n << "\n";
        return 0;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += x[i];
        if (s != 0) {
            cout << "YES\n";
            cout << "2\n";
            cout << "1 " << i << "\n";
            cout << i+1 << " " << n << "\n";
            return 0;
        }
    }
    cout << "NO\n";
}
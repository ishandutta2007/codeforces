#include <iostream>

using namespace std;

string a, b;
int n;
int c;

int main() {
    cin >> a >> b;
    n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) c++;
    }
    if (c%2 == 1) {
        cout << "impossible\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            cout << "0";
            continue;
        }
        if (a[i] == '0' && c%2 == 0) cout << 0;
        else if (a[i] == '1' && c%2 == 1) cout << 0;
        else cout << 1;
        c++;
    }
    cout << "\n";
}
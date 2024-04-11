#include <iostream>

using namespace std;

int n, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        if (x[0] == 'T') c += 4;
        if (x[0] == 'C') c += 6;
        if (x[0] == 'O') c += 8;
        if (x[0] == 'D') c += 12;
        if (x[0] == 'I') c += 20;
    }
    cout << c << "\n";
}
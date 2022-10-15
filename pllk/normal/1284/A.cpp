#include <iostream>

using namespace std;

int n, m;
string a[22], b[22];
int q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int y;
        cin >> y;
        y--;
        cout << a[y%n]+b[y%m] << "\n";
    }
}
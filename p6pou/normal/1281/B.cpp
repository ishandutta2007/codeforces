#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    string a, b;
    cin >> T;
    while (T --) {
        cin >> a >> b;
        int x = -1, sx = 0, sy = 0;
        for (int i = a.length() - 1; i >= 0; i --) {
            if (x != -1 && a[i] > a[x]) {
                sx = x;
                sy = i;
            }
            if (x == -1 || a[i] < a[x]) {
                x = i;
            }
        }
        swap(a[sx], a[sy]);
        if (a < b) {
            cout << a << endl;
        } else {
            cout << "---" << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    int x = a[0]-b[0];
    int y = a[1]-b[1];
    int mx = max(abs(x), abs(y));

    cout << mx << '\n';

    for (int i=0; i<mx; ++i) {
        if (x!=0) {
            if (x<0) {
                cout << 'R';
                x++;
            }
            else {
                cout << 'L';
                x--;
            }
        }
        if (y!=0) {
            if (y<0) {
                cout << 'U';
                y++;
            }
            else {
                cout << 'D';
                y--;
            }
        }
        cout << '\n';
    }

    return 0;
}
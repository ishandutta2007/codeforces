#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int l = 0;
    int r = n - 1;
    while (l != r) {
        int m = (l + r) / 2;
        cout << "? " << m + 1 << endl;
        int x;
        cin >> x;
        cout << "? " << m + 2 << endl;
        int y;
        cin >> y;
        if (x < y) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << "! " << l + 1 << endl;
    return 0;
}
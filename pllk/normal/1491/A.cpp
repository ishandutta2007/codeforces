#include <iostream>

using namespace std;

int a[101010];

int main() {
    int n, q;
    cin >> n >> q;
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) c0++;
        else c1++;
    }
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            a[x] = 1-a[x];
            if (a[x] == 0) {c0++; c1--;}
            else {c0--; c1++;}
        } else {
            int k;
            cin >> k;
            if (k <= c1) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}
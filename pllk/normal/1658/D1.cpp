#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int c1[20] = {0};
        for (int i = l; i <= r; i++) {
            for (int j = 0; j < 20; j++) {
                if (i&(1<<j)) c1[j]++;
            }
        }
        int c2[20] = {0};
        for (int i = l; i <= r; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < 20; j++) {
                if (x&(1<<j)) c2[j]++;
            }
        }
        int v = 0;
        for (int b = 0; b < 20; b++) {
            if (c1[b] != c2[b]) v ^= (1<<b);
        }
        cout << v << "\n";
    }
}
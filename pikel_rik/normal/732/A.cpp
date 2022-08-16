#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, r;
    cin >> k >> r;

    int t = k % 10;
    int i;

    for (i = 1;; i++) {
        if ((t * i) % 10 == r or (t * i) % 10 == 0)
            break;
    }
    cout << i;
    return 0;
}
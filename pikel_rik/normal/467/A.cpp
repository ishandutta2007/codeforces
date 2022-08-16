#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p, q, c = 0;


    for (int i = 0; i < n; i++) {
        cin >> p >> q;
        if (q - p >= 2)
            c += 1;
    }
    cout << c;
}
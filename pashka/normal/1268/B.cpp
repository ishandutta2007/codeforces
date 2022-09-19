#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    long s0 = 0, s1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) {
            s0 += x / 2;
            s1 += (x + 1) / 2;
        } else {
            s0 += (x + 1) / 2;
            s1 += x / 2;
        }
    }
    cout << min(s0, s1);

    return 0;
}
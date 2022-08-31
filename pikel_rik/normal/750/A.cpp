#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int t = 240 - k;

    int i;
    for (i = 1; i <= n; i++) {
        if (t - 5*i < 0)
            break;
        t -= 5*i;
    }

    cout << i - 1;
    return 0;
}
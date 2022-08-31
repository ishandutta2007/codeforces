#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;
    int tot = k * w * (w+1) / 2;

    if (tot - n > 0)
        cout << tot - n;
    else
        cout << 0;
    return 0;
}
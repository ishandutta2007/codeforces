#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (m * a < b)
        cout << n * a;
    else if ((n % m) * a < b)
        cout << b * (n/m) + (n % m) * a;
    else {
        if (n % m != 0)
            cout << b * (n / m + 1);
        else
            cout << b * (n / m);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int socks(int n, int m) {
    if (n < m)
        return n;
    if (n % m != 0)
        return n -n%m + socks(n/m + n%m, m);
    return n + socks(n/m, m);
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << socks(n, m);
    return 0;
}
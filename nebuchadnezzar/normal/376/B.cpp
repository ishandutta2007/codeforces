#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int n, m, a, b, c, mas[1000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        mas[a - 1] -= c;
        mas[b - 1] += c;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(mas[i]);
    }
    cout << ans / 2;

    return 0;
}
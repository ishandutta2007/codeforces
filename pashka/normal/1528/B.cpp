#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 1; return 0;
    }
    vector<int> d(n + 1);
    for (int x = 2; x <= n; x++) {
        for (int y = x * 2; y <= n; y += x) {
            d[y]++;
        }
    }
    long s = 2;
    long c = 0;
    for (int i = 2; i <= n; i++) {
        c = (s + 1 + d[i]) % 998244353;
        s += c;
        s %= 998244353;
    }
    cout << c << "\n";

    return 0;
}
#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

bool sq(int x) {
    int d = sqrt(x);
    while (d * d < x) d++;
    while (d * d > x) d--;
    return d * d == x;
}

void solve_test() {
    int n;
    cin >> n;
    if (n % 2 == 0 && sq(n / 2) || n % 4 == 0 && sq(n / 4)) {
            cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}
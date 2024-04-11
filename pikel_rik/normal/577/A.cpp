#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;

    int c = 0;

    for (long long i = 1; i <= n; i++) {
        if (x < i * i and x % i == 0) {
            c += 2;
        }
        else if (x == i * i) {
            c += 1;
        }
    }

    cout << c;

    return 0;
}
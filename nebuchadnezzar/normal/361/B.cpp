#include <cstdio>
#include <iostream>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;

    if (n == k) {
        cout << "-1";
        return 0;
    }
    if (n == k + 1) {
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        return 0;
    }

    cout << n << " ";
    for (int i = 2; i <= k + 1; ++i) {
        cout << i << " ";
    }

    cout << "1 ";
    for (int i = k + 2; i <= n - 1; ++i) {
        cout << i << " ";
    }

    return 0;
}
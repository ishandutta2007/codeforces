#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cur = 1;
    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                a[i] = a[j];
                break;
            }
        }
        if (!a[i]) {
            a[i] = cur++;
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
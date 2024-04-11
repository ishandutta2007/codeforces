#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
    }

    cout << (float)sum/n;

    return 0;
}
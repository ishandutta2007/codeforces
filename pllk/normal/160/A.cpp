#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    sort(&a[0], &a[n]);
    int k = 0, u = 0;
    for (int i = n-1; i >= 0; i--) {
        k++;
        u += a[i];
        if (u > s-u) break;
    }
    cout << k << endl;
}
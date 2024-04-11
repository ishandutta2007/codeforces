#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[50];

int main() {
    cin >> n >> k;
    if (k > n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(&a[0], &a[n]);
    cout << a[n-k] << " " << a[n-k] << endl;
}
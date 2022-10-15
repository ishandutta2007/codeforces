#include <iostream>

using namespace std;

int n, k;
int a[555];
int u[555];
int c;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        if (a[i-1]+a[i] < k) {
            c += k-(a[i-1]+a[i]);
            a[i] += k-(a[i-1]+a[i]);
        }
    }
    cout << c << "\n";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}
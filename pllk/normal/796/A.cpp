#include <iostream>

using namespace std;

int n, m, k;
int a[111];
int u = 999999999;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0 || a[i] > k) continue;
        u = min(u,abs(m-i));
    }
    cout << 10*u << "\n";
}
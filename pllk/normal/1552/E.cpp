#include <iostream>

using namespace std;

int n, k;
int x[10101];
int c[10101];
int a[111], b[111];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n*k; i++) cin >> x[i];
    int r = n / (k-1);
    if (n % (k-1) != 0) r++;
    for (int i = 1; i <= n*k; i++) {
        if (a[x[i]]) continue;
        int f = 0;
        for (int j = i; j >= 1; j--) {
            if (c[j] == r) break;
            if (i != j && x[j] == x[i]) {f = j; break;}
        }
        if (!f) continue;
        a[x[i]] = f;
        b[x[i]] = i;
        for (int j = f; j <= i; j++) c[j]++;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " " << b[i] << "\n";
}
#include <iostream>

using namespace std;

int n;
int a[101010];
int z[101010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int r = n;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i-1]) z[i] = 1;
        if (i <= 2) continue;
        if (a[i] == a[i-1] && a[i-1] == a[i-2]) {
            r--;
        }
        if (a[i] != a[i-1] && a[i] == a[i-2] && z[i-2]) z[i] = 1;
        if (i <= 4) continue;
        if (a[i] == a[i-1] && a[i-1] != a[i-2] && a[i] == a[i-3] && z[i-3]) {
            r--;
        }
    }
    cout << r << "\n";
}
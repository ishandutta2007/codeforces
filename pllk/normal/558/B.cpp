#include <iostream>

using namespace std;

int n;
int a[1010101];
int b[1010101];
int c[1010101];
int p;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (a[x] == 0) a[x] = i;
        b[x] = i;
        c[x]++;
        if (c[x] > p) p = c[x];
    }
    int z = 999999999;
    int l, r;
    for (int i = 1; i <= 1000000; i++) {
        if (c[i] != p) continue;
        if (b[i]-a[i] < z) {
            z = b[i]-a[i];
            l = a[i];
            r = b[i];
        }
    }
    cout << l << " " << r << "\n";
}
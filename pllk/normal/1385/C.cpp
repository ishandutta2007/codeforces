#include <iostream>

using namespace std;

int n;
int a[202020];

bool check(int k) {
    int x = k;
    int y = n;
    int v = 0;
    while (x <= y) {
        int u;
        if (a[x] < a[y]) {
            u = a[x]; x++;
        } else {
            u = a[y]; y--;
        }
        if (u < v) return false;
        v = u;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int k = 0;
        for (int b = n; b >= 1; b /= 2) {
            while (k+b <= n && !check(k+b)) k += b;
        }
        cout << k << "\n";
    }
}
#include <iostream>

using namespace std;

int n, k;

int a[1500000];
int c;

int main() {
    for (int i = 2; i < 1500000; i++) {
        if (a[i]) continue;
        c++;
        for (int j = 2*i; j < 1500000; j += i) {
            a[j] = 1;
        }
    }
    cin >> n >> k;
    if (n == 1) {
        if (k == 0) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    int u = n;
    if (u%2 == 1) u--;
    if (u/2 > k) {
        cout << -1 << endl;
        return 0;
    }
    k -= (u/2-1);
    int j = 2;
    for (int i = 0; i < u/2-1; i++) {
        while (a[j] || j == k || j == 2*k+1 || j == 2*k) j++;
        cout << j << " ";
        j++;
        while (a[j] || j == k || j == 2*k+1 || j == 2*k) j++;
        cout << j << " ";
        j++;
    }
    cout << k << " " << 2*k << " ";
    if (n > u) cout << 2*k+1 << " ";
    cout << endl;
}
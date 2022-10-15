#include <iostream>
#include <algorithm>

using namespace std;

int z[101010];
int n, k, x;
int a[101010];
int b[101010];

#define X 1024

int main() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        a[u]++;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < X; j++) b[j] = 0;
        int p = 0;
        for (int j = 0; j < X; j++) {
            b[j] += a[j]/2;
            b[j^x] += a[j]/2;
            if (a[j]%2 == 1 && p%2 == 0) b[j^x]++;
            if (a[j]%2 == 1 && p%2 == 1) b[j]++;
            p += a[j];
        }
        for (int j = 0; j < X; j++) a[j] = b[j];
    }
    for (int j = X-1; j >= 0; j--) {
        if (a[j]) {cout << j << " "; break;}
    }
    for (int j = 0; j < X; j++) {
        if (a[j]) {cout << j << " "; break;}
    }
    cout << "\n";
}
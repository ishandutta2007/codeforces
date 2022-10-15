#include <iostream>
#include <map>

using namespace std;

int x[10000001];
int a[202020];
int f[202020];

int what(int k) {
    int w = 1;
    while (true) {
        int u = x[k];
        if (u == 0) break;
        int c = 0;
        while (x[k] == u) {
            c++;
            k /= x[k];
        }
        if (k == u) {
            k = 1;
            c++;
        }
        if (c%2 == 1) w *= u;
    }
    if (k != 1) w *= k;
    return w;
}

int main() {
    for (int i = 2; i <= 10000000; i++) {
        if (x[i]) continue;
        for (int j = 2*i; j <= 10000000; j += i) {
            if (x[j] == 0) x[j] = i;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            a[i] = what(k);
        }
        map<int,int> w;
        for (int i = n; i >= 1; i--) {
            f[i] = w[a[i]];
            w[a[i]] = i;
        }
        int c = 0;
        int r = n;
        for (int i = 1; i <= n; i++) {
            if (f[i]) r = min(r,f[i]-1);
            if (i == r) {
                c++;
                r = n;
            }
        }
        cout << c << "\n";
    }
}
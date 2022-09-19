#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka


long cuberoot(long x) {
    long r = (long)cbrt(x);
//    while (r * r * r <= x) r++;
//    while (r * r * r > x) r--;
    return r;
}

struct test {
    void solve() {
        long x;
        cin >> x;
        for (long i = 1; i * i * i < x; i++) {
            long j = cuberoot(x - i * i * i);
            if (i * i * i + j * j * j == x) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}
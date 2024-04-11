#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

// @author: pashka

long long int calc(long long int n, long long int m);

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    long long n;
    cin >> n;

    long long l = 0;
    long long r = (long long int) 1e18;

    while (r > l + 1) {
        long long m = (l + r) >> 1;
        long long int s = calc(n, m);
        if (s >= n) {
            r = m;
        } else {
            l = m;
        }
    }

    if (calc(n, r) == n) {
        cout << r << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

long long int calc(long long int n, long long int m) {
    long long s = 0;
    for (long long k = 2; ; k++) {
            long long kk = k * k * k;
            long long x = m / kk;
            if (x == 0) break;
            s += x;
            if (s > n) break;
        }
    return s;
}
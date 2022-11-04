#include <bits/stdc++.h>

using namespace std;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

bool check(long long n, long long k) {
    long long v = 0, p = 0;
    while (n > 0) {
        v += min(k, n);
        n -= min(k, n);
        p += n / 10;
        n -= n / 10;
    }
    return v >= p;
}

void run() {
    long long n;
    cin >> n;
    long long left = 0;
    long long right = n;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (check(n, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << "\n";
}
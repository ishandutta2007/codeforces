#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
const int MAXN = 1e5 + 5;

int n;
long long a[MAXN], csum[MAXN];

long long sum(int l, int r) {
    return csum[r + 1] - csum[l];
}

int main() {
    cin >> n;
    --n;
    int trash;
    cin >> trash;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        csum[i + 1] = csum[i] + a[i];
    }

    long long ans = 1e18;
    for (int i = 1; i <= n && ans > i * i; ++i) {
        for (int j = 0; j + i - 1 < n; ++j) {
            ans = min(ans, (long long) (i * i + pow(sum(j, j + i - 1), 2)));
        }
        if (clock() / CLOCKS_PER_SEC > 1.6) {
            cout << ans << endl;
            return 0;
        }

    }

    cout << ans << endl;

    return 0;
}
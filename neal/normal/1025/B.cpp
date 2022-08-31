#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);
    long long g = 0;
    int a, b;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        g = __gcd(g, (long long) a * b);
    }

    if (g == 1) {
        printf("-1\n");
        return 0;
    }

    g = max(__gcd(g, (long long) a), __gcd(g, (long long) b));
    assert(g > 1);

    for (long long p = 2; p * p <= g; p++)
        if (g % p == 0) {
            cout << p << '\n';
            return 0;
        }

    cout << g << '\n';
    return 0;
}
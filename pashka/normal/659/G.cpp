#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>

// @author: pashka

#define MOD 1000000007L
using namespace std;


int main() {
    int n;
    scanf("%d", &n);

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    long long res = 0;

    long long s = 0;

    for (int i = 0; i < n; i++) {
        res += (h[i] - 1);
        res %= MOD;
        if (i > 0) {
            res += s * (min(h[i], h[i - 1]) - 1);
            res %= MOD;
        }
        if (i < n - 1) {
            if (s > 0) {
                s *= min(min(h[i], h[i - 1]), h[i + 1]) - 1;
                s %= MOD;
            }
            s += min(h[i], h[i + 1]) - 1;
            s %= MOD;
        }
    }

    cout << res;

    return 0;
}
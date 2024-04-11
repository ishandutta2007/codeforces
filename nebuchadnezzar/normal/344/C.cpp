#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <string.h>

using namespace std;

long long a, b;

int main() {
    cin >> a >> b;
    long long ans = 0;
    while (a > 0 && b > 0) {
        if (b > a) {
            ans += b / a;
            b = b % a;
        } else {
            ans += a / b;
            a = a % b;
        }
    }
    cout << ans;
    return 0;
}
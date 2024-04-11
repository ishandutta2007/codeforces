#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T;

bool prime(long long n) {
    if (n < 2)
        return false;

    if (n > 2 && n % 2 == 0)
        return false;

    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

string solve(long long A, long long B) {
    if (A - B > 1)
        return "NO";

    assert(A - B == 1);
    return prime(A + B) ? "YES" : "NO";
}

int main() {
    cin >> T;

    while (T--) {
        long long A, B;
        cin >> A >> B;
        cout << solve(A, B) << '\n';
    }
}
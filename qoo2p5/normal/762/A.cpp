#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    int k;
    cin >> n >> k;
    vector<long long> divisors;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d != 0) {
            continue;
        }
        divisors.push_back(d);
        if (d * d != n) {
            divisors.push_back(n / d);
        }
    }

    if (k > (int) divisors.size()) {
        cout << "-1\n";
    } else {
        nth_element(divisors.begin(), divisors.begin() + k - 1, divisors.end());
        cout << divisors[k - 1] << "\n";
    }

    return 0;
}
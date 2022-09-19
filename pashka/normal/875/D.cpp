#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

int main() {
    std::ios::sync_with_stdio(false);

    long n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        l[i] = i;
        while (l[i] > 0) {
            int x = l[i] - 1;
            if ((a[i] | a[x]) == a[i]) {
                l[i] = l[x];
            } else {
                break;
            }
        }
    }

    vector<int> r(n);
    for (int i = n - 1; i >= 0; i--) {
        r[i] = i;
        while (r[i] < n - 1) {
            int x = r[i] + 1;
            if (a[x] == a[i]) break;
            if ((a[i] | a[x]) == a[i]) {
                r[i] = r[x];
            } else {
                break;
            }
        }
    }

    long res = n * (n - 1) / 2 + n;

    for (int i = 0; i < n; i++) {
        long ll = i - l[i] + 1;
        long rr = r[i] - i + 1;
        res -= ll * rr;
    }

    cout << res << "\n";

    return 0;
}
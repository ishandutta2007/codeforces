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

    int n, k;
    cin >> n >> k;
    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long s = 0;
    long p = 1LL << 60;
    while (p > 0) {
        s += p;
        vector<vector<bool>> d(n + 1, vector<bool>(k + 1));
        d[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (!d[i][j]) continue;
                long t = 0;
                for (int q = i; q < n; q++) {
                    t += a[q];
                    if ((t & s) == s) {
                        d[q + 1][j + 1] = true;
                    }
                }
            }
        }
        if (!d[n][k]) {
            s -= p;
        }
        p >>= 1;
    }

    cout << s;

    return 0;
}
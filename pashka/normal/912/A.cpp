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

long max(long a, long b) {
    return a > b ? a : b;
}

int main() {
    std::ios::sync_with_stdio(false);

    long a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    a -= 2 * x + y;
    b -= 3 * z + y;
    cout << max(-a, 0L) + max(-b, 0L);

    return 0;
}
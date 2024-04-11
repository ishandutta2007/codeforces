#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define MAX_INT 2147483647
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::set;
using std::string;
using std::pair;
using std::cin;
using std::cout;

// @author: pashka

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = MAX_INT;
    for (int a = 1; ; a++) {
        int b = (n + a - 1) / a;
        res = std::min(res, a + b);
        if (b <= a) break;
    }

    cout << res * 2;

    return 0;
}
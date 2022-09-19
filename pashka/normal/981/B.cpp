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

    map<int, int> c;
    for (int i = 0; i < 2; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            c[x] = std::max(c[x], y);
        }
    }
    long s = 0;
    for (auto item : c) {
        s += item.second;
    }
    cout << s;
    return 0;
}
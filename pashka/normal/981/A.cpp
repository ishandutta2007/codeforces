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


bool pali(string s) {
    string r = s;
    std::reverse(r.begin(), r.end());
    return r == s;
}

int main() {
    std::ios::sync_with_stdio(false);

    string s;
    cin >> s;
    if (!pali(s)) {
        cout << s.size();
    } else if (!pali(s.substr(0, s.length() - 1))) {
        cout << s.size() - 1;
    } else {
        cout << 0;
    }

    return 0;
}
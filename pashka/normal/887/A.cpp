#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <fenv.h>

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

    string s;
    cin >> s;
    int c = 0;
    bool ok = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') ok = true;
        if (ok && s[i] == '0') c++;
    }

    cout << ((c >= 6) ? "yes" : "no") << "\n";

    return 0;
}
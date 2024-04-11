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
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    cout << 1;

    vector<bool> z(n + 1);
    int max = n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        z[x] = true;
        while (z[max]) max--;
        cout << " " << (max - (n - i) + 2);
    }

    cout << "\n";


    return 0;
}
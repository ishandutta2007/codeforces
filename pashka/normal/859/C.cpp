#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

#define MAX_INT 2147483647
#define PI 3.141592653589793238462643383279502884L

#define long long long int

using std::vector;
using std::map;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::cerr;

// @author: pashka

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s = 0;
    int d = 0;
    for (int i = n - 1; i >= 0; i--) {
        d = std::max(a[i] - d, - a[i] + d);
        s += a[i];
    }

    cout << (s - d) / 2 << " " << (s + d) / 2 << "\n";

    return 0;
}
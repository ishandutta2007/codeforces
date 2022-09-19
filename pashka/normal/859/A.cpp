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

// @author: pashka

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        max = std::max(max, x);
    }

    cout << std::max(max - 25, 0);

    return 0;
}
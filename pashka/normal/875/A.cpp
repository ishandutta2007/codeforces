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

    vector<int> res;

    for (int c = n; c >= 0; c--) {
    	if (c < n - 9 * 9) break;
    	int s = 0;
    	int k = c;
    	while (k > 0) {
    		s += k % 10;
    		k /= 10;
    	}
    	if (c + s == n) {
    		res.push_back(c);
    	}
    }

    std::sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int q : res) {
    	cout << q << "\n";
    }
    
    return 0;
}
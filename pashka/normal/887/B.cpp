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

    int n;
    cin >> n;
    vector<vector<bool>> q(n, vector<bool>(10));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            int x;
            cin >> x;
            q[i][x] = true;
        }
    }
    int x;
    for (x = 1; ; x++) {
        vector<int> c;
        int xx = x;
        while (xx > 0) {
            c.push_back(xx % 10);
            xx /= 10;
        }
        if (c.size() > n) {
            cout << (x - 1);
            return 0;
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) p[i] = i;
        while (true) {
            bool ok = true;
            for (int j = 0; j < c.size(); j++) {
                if (!q[p[j]][c[j]]) {
                    ok = false;
                }
            }
            if (ok) break;
            if (!std::next_permutation(p.begin(), p.end())) {
                cout << (x - 1);
                return 0;
            }
        }
    }

    return 0;
}
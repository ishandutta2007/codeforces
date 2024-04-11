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

    vector<int> c(24);
    for (int i = 0; i < 24; i++) {
        cin >> c[i];
    }
    vector<vector<int>> rot = {{0, 2, 4, 6, 8, 10, 23, 21}, {2, 3, 16, 18, 9, 8, 15, 13}, {12, 13, 4, 5, 16, 17, 20, 21}};
    for (int i = 0; i < rot.size(); i++) {
        for (int j = 0; j < 8; j++) {
            int t = c[rot[i][7]];
            for (int k = 0; k < 8; k++) {
                int tt = c[rot[i][k]];
                c[rot[i][k]] = t;
                t = tt;
            }
            if (j == 1 || j == 5) {
//                for (int x : c) {
//                    cout << x << " ";
//                }
//                cout << "\n";
                bool ok = true;
                for (int t = 0; t < 6; t++) {
                    for (int u = 0; u < 4; u++) {
                        if (c[t * 4 + u] != c[t * 4]) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}
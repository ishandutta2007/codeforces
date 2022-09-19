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

    int n, m;
    cin >> n >> m;
    int nn = 1 << n;
    vector<bool> z(2 * nn);
    vector<int> q(2 * nn);
    int h = 0;
    int t = 0;

    for (int i = 0; i < nn; i++) {
        z[i] = true;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        z[x] = false;
    }

    int res = 0;
    for (int i = 0; i < nn; i++) {
        if (!z[i]) {
            res++;
            z[i] = true;
            q[t++] = i;
            while (t > h) {
                int x = q[h++];
                if (x < nn) {
                    int y = nn + nn - 1 - x;
//                    cout << x << " " << y << "\n";
                    if (!z[y]) {
                        z[y] = true;
                        q[t++] = y;
                    }
                } else {
                    for (int j = 0; j < n; j++) {
                        int y = x & ~(1 << j);
//                        cout << x << " " << y << "\n";
                        if (!z[y]) {
                            z[y] = true;
                            q[t++] = y;
                        }
                    }
                    int y = x - nn;
//                    cout << x << " " << y << "\n";
                    if (!z[y]) {
                        z[y] = true;
                        q[t++] = y;
                    }
                }
            }
        }
    }

    cout << res;

    return 0;
}
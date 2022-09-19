#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

#define MAX_INT 2147483647
#define MOD 1000000007L
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
    n = 1 << n;

    vector<vector<double>> p(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            p[i][j] *= 0.01;
        }
    }

    vector<double> dp(n);
    vector<double> pa(n, 1);

    for (int w = 0; (1 << w) < n; w++) {
        vector<double> pa2(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> (w + 1)) == (j >> (w + 1)) && (i >> w) != (j >> w)) {
                    pa2[i] += pa[j] * p[i][j];
                }
            }
            pa2[i] *= pa[i];
        }
        pa = pa2;
//        for (auto item : pa) {
//            cout << item << " ";
//        }
//        cout << "\n";

        vector<double> dp2(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> (w + 1)) == (j >> (w + 1)) && (i >> w) != (j >> w)) {
                    dp2[i] = std::max(dp2[i], dp[j]);
                }
            }
            dp2[i] += pa[i] * (1 << w) + dp[i];
        }
        dp = dp2;
    }

    double res = 0;
    for (int i = 0; i < n; i++) {
        res = std::max(res, dp[i]);
    }

    cout << std::setprecision(20);
    cout << res;

    return 0;
}
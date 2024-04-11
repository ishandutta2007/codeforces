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

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<vector<int>> d(n, vector<int>(k, MAX_INT));
    vector<int> q(n);

    for (int cc = 0; cc < k; cc++) {
        int t = 0;
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] == cc) {
                d[i][cc] = 0;
                q[t++] = i;
            }
        }
        while (t > h) {
            int x = q[h++];
            for (int y : g[x]) {
                if (d[y][cc] == MAX_INT) {
                    d[y][cc] = d[x][cc] + 1;
                    q[t++] = y;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::sort(d[i].begin(), d[i].end());
        long ss = 0;
        for (int j = 0; j < s; j++) {
            ss += d[i][j];
        }
        cout << ss << " ";
    }
    cout << "\n";


    return 0;
}
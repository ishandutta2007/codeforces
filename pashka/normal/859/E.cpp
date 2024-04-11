#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

#define MAX_INT 2147483647
#define PI 3.141592653589793238462643383279502884L

#define long long long int

#define MOD 1000000007;
using std::vector;
using std::map;
using std::string;
using std::pair;
using std::cin;
using std::cout;

// @author: pashka

int n;
vector<vector<int>> g;
vector<int> z;

int nn = 0;
int mm = 0;
bool loop;

void dfs(int x) {
    if (z[x]) return;
    z[x] = 1;
    nn++;
    for (int y : g[x]) {
        mm++;
        dfs(y);
        if (y == x) loop = true;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    g.resize(2 * n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    z.resize(2 * n);
    long res = 1;
    for (int i = 0; i < 2 * n; i++) {
        if (!z[i]) {
            nn = 0;
            mm = 0;
            loop = false;
            dfs(i);
            mm /= 2;
            if (mm > nn) {
                cout << "0\n";
                return 0;
            }
            if (mm == nn) {
                if (!loop)
                    res = (res * 2) % MOD;
            } else {
                res = (res * nn) % MOD;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
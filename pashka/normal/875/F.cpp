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

vector<int> p;

int get(int x) {
    if (p[x] != x) {
        p[x] = get(p[x]);
    }
    return p[x];
}

void join(int x, int y) {
    p[x] = y;
}

int main() {
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;

    vector<pair<int, pair<int, int>>> e(m);

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        e[i] = {w, {x, y}};
    }

    sort(e.begin(), e.end());

    vector<bool> cycle(n);
    long res = 0;
    for (int i = m - 1; i >= 0; i--) {
        int x = e[i].second.first;
        int y = e[i].second.second;
        x = get(x);
        y = get(y);
        if (x != y) {
            if (!cycle[x] || !cycle[y]) {
                bool cc = cycle[x] || cycle[y];
                res += e[i].first;
                join(x, y);
                cycle[get(x)] = cc;
            }
        } else {
            if (!cycle[x]) {
                res += e[i].first;
                cycle[x] = true;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
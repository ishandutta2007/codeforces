#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define puba push_back
#define mapa make_pair

using namespace std;

int n, m, maxac, minac = 101, mintl = 101, num, ac;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        minac = min(minac, num);
        maxac = max(maxac, num);
    }

    for (int i = 0; i < m; ++i) {
        cin >> num;
        mintl = min(mintl, num);
    }
    ac = max(minac * 2, maxac);
    if (ac >= mintl) {
        cout << "-1";
    } else {
        cout << ac;
    }

    return 0;
}
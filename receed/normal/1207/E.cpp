#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n = 100, res = 0, x, m = (1 << 7) - 1;
    for (int i : {0, 7}) {
        cout << "?";
        for (int j = 1; j <= 100; j++)
            cout << ' ' << (j << i);
        cout << endl;
        cin >> x;
        res += x & (m << (7 - i));
    }
    cout << "! " << res << endl;
}
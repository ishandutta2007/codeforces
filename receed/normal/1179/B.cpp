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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
    cin >> n >> m;
    int d = 1;
    for (int k = 1; k <= (m + 1) / 2; k++)
        for (int i = 1; i <= (k * 2 == m + 1 ? (n + 1) / 2 : n); i++) {
            cout << i << ' ' << k << '\n';
            if (k * 2 != m + 1 || i * 2 != n + 1)
                cout << n + 1 - i << ' ' << m + 1 - k << '\n';
        }
}
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

const int N = 300001;
int a[N], pos[N];
int n;	
vector<pair<int, int>> res;

void sw(int x, int y) {
	if (x == y)
		return;
	assert(abs(x - y) >= n / 2);
	res.push_back({x + 1, y + 1});
	swap(a[x], a[y]);
	pos[a[x]] = x;
	pos[a[y]] = y;
}

void sw2(int x, int y) {
	if (x > y)
		swap(x, y);
	if (y - x >= n / 2)
		sw(x, y);
	else if (x >= n / 2) {
		sw(x, 0);
		sw(y, 0);
		sw(x, 0);
	}
	else if (y < n / 2) {
		sw(x, n - 1);
		sw(y, n - 1);
		sw(x, n - 1);
	}
	else {
		sw(y, 0);
		sw(x, n - 1);
		sw(0, n - 1);
		sw(y, 0);
		sw(x, n - 1);
	}
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i, n) {
    	cin >> a[i];
    	a[i]--;
    	pos[a[i]] = i;
    }
    rep(i, n) {
    	if (pos[i] != i)
    		sw2(pos[i], i);
    }
    rep(i, n)
    	assert(a[i] == i);
    cout << res.size() << '\n';
    for (auto &pp : res)
    	cout << pp.first << ' ' << pp.second << '\n';
}
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
	int n;
	cin >> n;
	vector<int> c(3);
	vector<vector<vector<int>>> a(2);
	rep(i, n) {
		cin >> c[0] >> c[1];
		c[2] = i + 1;
		if (c[0] < c[1])
			a[0].push_back(c);
		else
			a[1].push_back(c);
	}
	if (a[0].size() > a[1].size()) {
		sort(rall(a[0]));
		cout << a[0].size() << '\n';
		for (auto &pp : a[0])
			cout << pp[2] << ' ';
	}
	else {
		sort(all(a[1]));
		cout << a[1].size() << '\n';
		for (auto &pp : a[1])
			cout << pp[2] << ' ';	
	}
}
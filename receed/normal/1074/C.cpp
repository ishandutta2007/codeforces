#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	vector<int> p(4, -1);
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		if (p[0] == -1 || a[i].first < a[p[0]].first)
			p[0] = i;
		if (p[1] == -1 || a[i].first > a[p[1]].first)
			p[1] = i;
		if (p[2] == -1 || a[i].second < a[p[2]].second)
			p[2] = i;
		if (p[3] == -1 || a[i].second > a[p[3]].second)
			p[3] = i;
	}
	int a1 = 0, a2 = (a[p[1]].first - a[p[0]].first + a[p[3]].second - a[p[2]].second) * 2;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < i; j++) {
			int x = p[i], y = p[j];
			for (int k = 0; k < n; k++) {
				a1 = max(a1, max(abs(a[x].first - a[y].first), max(abs(a[x].first - a[k].first), abs(a[y].first - a[k].first))) + 
							 max(abs(a[x].second - a[y].second), max(abs(a[x].second - a[k].second), abs(a[y].second - a[k].second))));
			}
		}
	cout << a1 * 2 << ' ';
	for (int i = 0; i < n - 3; i++)
		cout << a2 << ' ';
}
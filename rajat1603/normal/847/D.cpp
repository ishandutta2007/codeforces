#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false)

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

vector<pll> events;

int main()
{
	fast_cin();

	int N; ll T;
	cin >> N >> T;
	for (int i = 1; i <= N; ++i) {
		ll t;
		cin >> t;
		ll st = t - i;
		ll et = T - i;
		if (et > st && et > 0) {
			events.push_back({st, 1});
			events.push_back({et, -1});
		}
	}

	sort(events.begin(), events.end());
	int curr = 0, mx = 0;
	for (auto &x : events) {
		curr += x.second;
		mx = max(mx, curr);
	}

	cout << mx << endl;
}
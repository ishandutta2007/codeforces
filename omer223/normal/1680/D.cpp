#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

ll foo(vector<ll> v) {
	int n = v.size();
	ll mn = 0, mx = 0, sm= 0;
	foru(i, 0, n) {
		sm += v[i];
		mn = min(mn, sm);
		mx = max(mx, sm);
	}
	return mx - mn + 1;
}

pll valsect(ll x1, ll y1, ll x2, ll y2) {
	return { max(x1,x2),min(y1,y2) };
}

int main() {
	fast;
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	foru(i, 0, n)cin >> v[i];
	ll zs = 0, sm = 0;
	foru(i, 0, n) {
		if (v[i] == 0)zs++;
		else sm += v[i];
	}
	if (k * zs < abs(sm)) {
		cout << -1 << '\n';
		return 0;
	}
	ll bst = 0;
	for (int pivot = 0; pivot <= n; pivot++) {
		ll need = -sm, rem = zs;
		vector<ll> u = v;
		for (int i = 0; i < pivot; i++) {
			if (u[i] != 0)continue;
			pll val = valsect(-k, k, need - k * (rem - 1), need + k * (rem - 1));
			u[i] = val.ff;
			need -= u[i];
			rem--;
		}
		for (int i = pivot; i < n; i++) {
			if (u[i] != 0)continue;
			pll val = valsect(-k, k, need - k * (rem - 1), need + k * (rem - 1));
			u[i] = val.ss;
			need -= u[i];
			rem--;
		}
		bst = max(bst, foo(u));
	}
	for (int pivot = 0; pivot <= n; pivot++) {
		ll need = -sm, rem = zs;
		vector<ll> u = v;
		for (int i = 0; i < pivot; i++) {
			if (u[i] != 0)continue;
			pll val = valsect(-k, k, need - k * (rem - 1), need + k * (rem - 1));
			u[i] = val.ss;
			need -= u[i];
			rem--;
		}
		for (int i = pivot; i < n; i++) {
			if (u[i] != 0)continue;
			pll val = valsect(-k, k, need - k * (rem - 1), need + k * (rem - 1));
			u[i] = val.ff;
			need -= u[i];
			rem--;
		}
		bst = max(bst, foo(u));
	}
	cout << bst << '\n';
	return 0;
}
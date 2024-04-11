#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 100005;
const long long MAXMUL = (long long)MAXSIZE * (long long)MAXSIZE;

long long Dfs(const vector<pair<int, int>> factors, int dep, long long x, long long y, const vector<int>& count) {
	if (dep == factors.size()) {
		if (x == y) {
			return (x < MAXSIZE) ? (long long)count[x] * (long long)(count[x] - 1) / 2 : 0;
		} else {
			return (x < y && y < MAXSIZE) ? (long long)count[x] * (long long)count[y] : 0;
		}
	}
	pair<int, int> p = factors[dep];
	for (int i = 0; i < p.second; ++i) {
		y *= p.first;
	}
	long long results = 0;
	for (int i = 0; i <= p.second; ++i) {
		results += Dfs(factors, dep + 1, x, y, count);
		x *= p.first;
		y /= p.first;
	}
	return results;
}

long long Solve(const vector<int>& a, int k) {
	vector<int> factor(MAXSIZE);
	for (int n = 2; n < MAXSIZE; ++n) {
		if (!factor[n]) {
			for (int k = n; k < MAXSIZE; k += n) {
				factor[k] = n;
			}
		}
	}
	vector<int> count(MAXSIZE);
	for (int n : a) {
		++count[n];
	}
	long long results = 0;
	for (int x = 1; x < MAXSIZE; ++x) {
		long long target = 1;
		for (int i = 0; i < k; ++i) {
			target *= x;
			if (target > MAXMUL) {
				break;
			}
		}
		if (target > MAXMUL) {
			break;
		}
		vector<pair<int, int>> factors;
		for (int val = x; val > 1; ) {
			int p = factor[val];
			int e = 0;
			while (val % p == 0) {
				val /= p;
				e += k;
			}
			factors.emplace_back(p, e);
		}
		results += Dfs(factors, 0, 1, 1, count);
	}
	return results;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << Solve(a, k) << endl;
	return 0;
}
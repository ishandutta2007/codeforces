#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> solve(const vector<ll>& a, int s, int t, int m) {
	if (s > t) {
		return { 0 };
	}
	int n = t - s + 1;
	int p = s;
	for (int i = s; i <= t; i++) {
		if (a[i] < a[p]) {
			p = i;
		}
	}
	vector<ll> f1 = solve(a, s, p - 1, m);
	vector<ll> f2 = solve(a, p + 1, t, m);
	vector<ll> f(min(n, m) + 1, -(1LL << 62));
	for (int i = 0; i < f1.size(); ++i) {
		for (int j = 0; j < f2.size(); ++j) {
			if (i + j < f.size()) {
				f[i + j] = max(f[i + j], f1[i] + f2[j] - a[p] * (i * j * 2));
			}
			if (i + j + 1 < f.size()) {
				f[i + j + 1] = max(f[i + j + 1], a[p] * (m - 1) + f1[i] + f2[j] - (ll)a[p] * ((i * j + i + j) * 2));
			}
		}
	}
	return f;
}

void doit(int n, int m) {
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> f = solve(a, 0, n - 1, m);
	cout << f[m] << endl;
}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		doit(n, m);
	}
	return 0;
}
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int MOD;

inline int ADD(int a, int b) { 
	return (a + b >= MOD) ? (a + b - MOD) : (a + b); 
}

inline int SUB(int a, int b) { 
	return (a >= b) ? (a - b) : (a - b + MOD); 
}


int solve(int n, int m) {
	MOD = m;
	vector<int> f(n + 1);
	f[1] = 1;
	int s = 1;
	int cur = 0;
	vector<int> g(n + 1);
	for (int i = 2; i <= n; ++i) {
		if (!g[i]) {
			for (int j = i; j <= n; j += i) {
				g[j] = i;
			}
		}
	}
	for (int x = 2; x <= n; ++x) {
		cur = ADD(cur, f[1]);
		vector<int> p;
		vector<int> e;
		for (int y = x; y > 1; ) {
			int p0 = g[y];
			int e0 = 0;
			while (y % p0 == 0) {
				y /= p0;
				++e0;
			}
			p.push_back(p0);
			e.push_back(e0);
		}
		std::function<void(int, int)> dfs = [&](int d, int z) {
			if (d == p.size()) {
				if (z > 1 && z < x) {
					cur = SUB(cur, f[z - 1]);
					cur = ADD(cur, f[z]);
				}
			} else {
				for (int i = 0; i <= e[d]; ++i) {
					dfs(d + 1, z);
					z *= p[d];
				}
			}
		};
		dfs(0, 1);
		f[x] = ADD(s, cur);
		s = ADD(s, f[x]);
	}
	return f[n];
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, m; 
	while (cin >> n >> m) {
#ifdef _MSC_VER
		double t1 = clock();
#endif
		cout << solve(n, m) << endl;
#ifdef _MSC_VER
		double t2 = clock();
		//cout << "  RT = " << (t2 - t1) / CLOCKS_PER_SEC << endl;
#endif
	}
	return 0;
}
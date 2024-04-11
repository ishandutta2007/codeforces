#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

std::vector<std::vector<int> > matrix_mult(std::vector<std::vector<int> >& a, std::vector<std::vector<int> >& b, int mod)
{
	std::vector<std::vector<int> > gr(a.size(), std::vector<int> (a.size(), 0));
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < a.size(); ++j)
			for (int k = 0; k < a.size(); ++k)
				gr[i][j] = (gr[i][j] + a[i][k] * b[k][j]) % mod;
	return gr;
}
std::vector<std::vector<int> > matrix_expo(std::vector<std::vector<int> >& a, int n, int mod)
{
	std::vector<std::vector<int> > res(a.size(), std::vector<int> (a.size(), 0));
	for (int i = 0; i < a.size(); ++i)
		res[i][i] = 1;
	while (n) {
		if (n & 1ll)
			res = matrix_mult(res, a, mod);
		a = matrix_mult(a, a, mod);
		n >>= 1;
	}
	return res;
}

int cnt(int o) {
	int u = 0;
	for (int i = 0; i < 62; ++i) {
		if (o & (1ll << i)) {
			u++; 
		}
	}  
	return u;
}


int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n, k;
	cin >> n >> k;
	std::vector<std::vector<int> > gr(n, std::vector<int> (n, 0));
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (cnt(a[i] ^ a[j]) % 3 == 0) {
				gr[i][j] = 1;
				gr[j][i] = 1;
			} 
		}
	}
	auto res = matrix_expo(gr, k - 1ll, 1e9 + 7);
	int MOD = 1e9 + 7;
	int y = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			y = (y + res[i][j]) % MOD;
		}
	}
	cout << y;
}
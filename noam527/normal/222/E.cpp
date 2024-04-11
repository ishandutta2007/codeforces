#include <iostream>
#include <algorithm>
#include <vector>
int md = 1e9 + 7;
typedef long long ll;
using namespace std;

struct matrix {
	vector<vector<int>> a;
	void init(int h, int w, int t) {
		a.resize(h, vector<int>(w, 0));
		if (t == 1)
			for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) a[i][j] = 1;
	}
	void operator *= (matrix &b) {
		matrix rtn;
		rtn.init(a.size(), b.a[0].size(), -1);
		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < b.a[i].size(); j++) {
				rtn.a[i][j] = 0;
				for (int k = 0; k < a[0].size(); k++)
					rtn.a[i][j] = (rtn.a[i][j] + (ll)a[i][k] * b.a[k][j]) % md;
			}
		*this = rtn;
	}
	void pow(matrix b, ll e) {
		while (e) {
			if (e & 1) *this *= b;
			e /= 2, b *= b;
		}
	}
	int sum() {
		int rtn = 0;
		for (auto &i : a) for (auto &j : i) rtn = (rtn + j) % md;
		return rtn;
	}
};

int main() {
	ios::sync_with_stdio(0);
	ll n, m, k;
	cin >> n >> m >> k;
	matrix a, b;
	a.init(1, m, 1), b.init(m, m, 1);
	while (k--) {
		char c, d;
		cin >> c >> d;
		if (c <= 'Z') c = c - 'A' + 26;
		else c = c - 'a';
		if (d <= 'Z') d = d - 'A' + 26;
		else d = d - 'a';
		b.a[d][c] = 0;
	}
	a.pow(b, n - 1);
	cout << a.sum() << endl;
}
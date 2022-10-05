#include <iostream>
#include <algorithm>
#include <vector>
int md = 1e9 + 7;
typedef long long ll;
using namespace std;

struct matrix {
	vector<vector<int>> a;
	void init(int h, int w, int t = -1) {
		a.resize(h, vector<int>(w, 0));
		if (t == 0) {
			a[0][0] = a[0][1] = a[h - 1][h - 2] = a[h - 1][h - 1] = 1;
			for (int i = 1; i < h - 1; i++)
				a[i][i - 1] = a[i][i] = a[i][i + 1] = 1;
		}
		else if (t == 1)
			a[0][0] = 1;
	}
	matrix operator * (matrix &b) {
		matrix res;
		res.init(a.size(), b.a[0].size());
		for (int i = 0; i < res.a.size(); i++)
			for (int j = 0; j < res.a[i].size(); j++) {
				res.a[i][j] = 0;
				for (int k = 0; k < a[0].size(); k++)
					res.a[i][j] = (res.a[i][j] + (ll)a[i][k] * b.a[k][j]) % md;
			}
		return res;
	}
	void pow(matrix t, ll e) {
		while (e) {
			if (e & 1) *this = *this * t;
			e /= 2, t = t * t;
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	int n, c;
	ll k, l, r;
	cin >> n >> k;
	matrix m;
	m.init(1, 16, 1);
	while (n--) {
		cin >> l >> r >> c;
		r = min(k, r);
		int prev = m.a[0].size();
		m.a[0].resize(c + 1);
		for (; prev < m.a[0].size(); prev++) m.a[0][prev] = 0;

		if (c == 0) continue;

		matrix temp;
		temp.init(c + 1, c + 1, 0);
		m.pow(temp, r - l);
	}
	cout << m.a[0][0] << endl;
}
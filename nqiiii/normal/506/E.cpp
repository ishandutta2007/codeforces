#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;

inline int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
inline void addto(int &x, int y) {
	x += y; if (x >= mod) x -= mod;
}
inline int dec(int x, int y) {
	x -= y; return x < 0 ? x + mod : x;
}
inline void decto(int &x, int y) {
	x -= y; if (x < 0) x += mod;
}
inline int mul(int x, int y) {
	return x * y % mod;
}
int fpow(int x, int y = mod - 2) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

namespace bm {
	const int maxn = 10000;
	vector<int> r[maxn + 10];
	int rcnt, pos[maxn + 10], w[maxn + 10];

	vector<int> main(vector<int> a) {
		rcnt = 0;
		for (int i = 0; i < (int)a.size(); ++i) {
			int delta = a[i];
			for (int j = 0; j < (int)r[rcnt].size(); ++j)
				decto(delta, mul(r[rcnt][j], a[i - j - 1]));
			if (delta) {
				pos[rcnt] = i; w[rcnt] = delta;
				if (!rcnt) {
					r[++rcnt].clear(); r[rcnt].resize(i + 1);
				} else {
					int id = 0;
					for (int j = 1; j < rcnt; ++j)
						if (i - pos[j] + r[j].size() < i - pos[id] + r[id].size()) id = j;
					++rcnt;
					r[rcnt].resize(max(r[id].size() + i - pos[id], r[rcnt - 1].size()));
					int t = mul(delta, fpow(w[id], mod - 2));
					for (int j = 0; j < i - pos[id] - 1; ++j) r[rcnt][j] = 0;
					r[rcnt][i - pos[id] - 1] = t;
					for (int j = 0; j < (int)r[id].size(); ++j)
						r[rcnt][j + i - pos[id]] = mul(dec(0, t), r[id][j]);
					for (int j = 0; j < (int)r[rcnt - 1].size(); ++j)
						addto(r[rcnt][j], r[rcnt - 1][j]);
				}
			}
		}
		return r[rcnt];
	}
}

int f[210][210], g[210][210];
char s[210];
int n, m;
vector<int> a, b, tmp, ans;

vector<int> operator * (const vector<int> &a, const vector<int> &b) {
	vector<int> ans((int)a.size() + b.size() - 1);
	for (int i = 0; i < (int)a.size(); ++i)
		for (int j = 0; j < (int)b.size(); ++j)
			addto(ans[i + j], mul(a[i], b[j]));
	return ans;
}

vector<int> operator % (vector<int> a, const vector<int> &b) {
	for (int i = (int)a.size() - 1; i >= (int)b.size() - 1; --i) {
		int w = a[i];
		for (int j = (int)b.size() - 1; j >= 0; --j)
			decto(a[i + j - (int)b.size() + 1], mul(b[j], w));
	}
	while (!a.empty() && !a.back()) a.pop_back();
	return a;
}

void insans() {
	int ans = f[0][0];
	if (m & 1) {
		ans = mul(ans, 26);
		for (int j = 1; j <= n; ++j)
			addto(ans, f[j - 1][j + 1]);
	}
	a.push_back(ans);
}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	scanf("%d", &m);
	m += n; f[0][n + 1] = 1;
	for (int i = 0; i <= 2000; ++i) {
		insans(); memset(g, 0, sizeof g);
		g[0][0] = mul(f[0][0], 26);
		for (int j = 0; j <= n; ++j)
			for (int k = j + 2; k <= n + 1; ++k)
				if (f[j][k]) {
					if (s[j + 1] == s[k - 1]) {
						addto(g[j][k], mul(f[j][k], 25));
						int tj = j + 1, tk = k - 1;
						if (tj + 1 >= tk) tj = tk = 0;
						addto(g[tj][tk], f[j][k]);
					} else {
						addto(g[j][k], mul(f[j][k], 24));
						int tj = j + 1, tk = k;
						if (tj + 1 >= tk) tj = tk = 0;
						addto(g[tj][tk], f[j][k]);
						tj = j, tk = k - 1;
						if (tj + 1 >= tk) tj = tk = 0;
						addto(g[tj][tk], f[j][k]);
					}
				}
		memcpy(f, g, sizeof g);	
	}
	m /= 2;
	b = bm::main(a);
	reverse(b.begin(), b.end());
	for (int i = 0; i < (int)b.size(); ++i) b[i] = dec(0, b[i]);
	b.push_back(1);
	ans.push_back(1); tmp.push_back(0); tmp.push_back(1);
	while (m) {
		if (m & 1) ans = ans * tmp % b;
		m >>= 1; tmp = tmp * tmp % b;
	}
	int res = 0;
	for (int j = 0; j < (int)ans.size(); ++j)
		addto(res, mul(a[j], ans[j]));
	printf("%d ", res);
}
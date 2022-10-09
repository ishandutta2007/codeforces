#include <bits/stdc++.h>

const int N = 5e5 + 50;

int n, siz[N], fa[N];
std::vector<int> G[N];
long long f[N], ans = 1e18;

inline void add(int x, int y) {
	G[x].push_back(y);
}
long long sq(long long x) {
	return x * x;
}

void dfs1(int x, int _fa = 0) {
	fa[x] = _fa;
	siz[x] = 1;
	for (int y : G[x])
		if (y != _fa) {
			dfs1(y, x);
			siz[x] += siz[y];
		}
}

int que[N], qtot;
void dfs2(int x) {
	f[x] = sq(siz[x]);
	std::vector<int> son;
	for (int y : G[x])
		if (y != fa[x]) {
			dfs2(y);
			f[x] = std::min(f[x], f[y] + sq(siz[x] - siz[y]));
			ans = std::min(ans, f[y] + sq(n - siz[y]));
			son.push_back(y);
		}
	std::sort(son.begin(), son.end(), [&](int x, int y) {
		return siz[x] < siz[y];
	});
	qtot = 0;
	auto solve = [&](long long cons, long long k) -> long long {
		return 1e18;
	};
	auto get_b = [&](int i) -> long long {
		return f[i] + sq(siz[i]);
	};
	auto get_x = [&](int i) -> long long {
		return siz[i];
	};
	auto check = [&](int i, int j, int k) -> bool {
		// check if slope(j->k) <= slope(i->j)
		// (b[k] - b[j]) / (x[k] - x[j]) <= (b[j] - b[i]) / (x[j] - x[i])
		long long b_i = get_b(i), b_j = get_b(j), b_k = get_b(k);
		long long x_i = get_x(i), x_j = get_x(j), x_k = get_x(k);
		assert(x_k >= x_j && x_j >= x_i);
		return (b_k - b_j) * (x_j - x_i) <= (b_j - b_i) * (x_k - x_j);
	};
	auto check2 = [&](int i, int j, int k) -> bool {
		// check slope(i->j) <= k
		// (b[j] - b[i]) / (x[j] - x[i]) <= k
		long long b_i = get_b(i), b_j = get_b(j);
		long long x_i = get_x(i), x_j = get_x(j);
		return (b_j - b_i) <= k * (x_j - x_i);
	};
	int p = 1;
	for (int i = 0; i < (int)son.size(); ++i) {
		int y = son[i];
		long long cons = f[y] + sq(n - siz[y]);
		long long k = -2ll * (n - siz[y]);
		//printf("y = %d, k = %lld, b = %lld, x = %lld\n", y, k, get_b(y), get_x(y));
		ans = std::min(ans, solve(cons, k));
		while (p < qtot && check2(que[p], que[p + 1], -k)) ++p;
		//printf("p = %d\n", p);
		if (1 <= p && p <= qtot) {
			long long t = cons + get_b(que[p]) + 1ll * k * get_x(que[p]);
			if (ans > t) {
				//printf("x = %d, y = %d, que[p] = %d, t = %lld, get_b = %lld, get_x = %lld\n", x, y, que[p], t, get_b(que[p]), get_x(que[p]));
			}
			ans = std::min(ans, t);
		}

		while (qtot >= 2 && check(que[qtot - 1], que[qtot], y)) {
			//printf("delete %d\n", que[qtot]);
			--qtot;
		}
		que[++qtot] = y;
		p = std::min(p, qtot);
		//for (int j = 1; j <= qtot; ++j)
		//	ans = std::min(ans, cons + get_b(que[j]) + 1ll * k * get_x(que[j]));
		/*for (int j = 1; j + 2 <= qtot; ++j) {
			assert(!check(que[j], que[j + 1], que[j + 2]));
		}*/
		
		/*for (int j = 0; j < i; ++j) {
			int z = son[j];
			long long x = siz[z];
			long long b = f[z] + sq(siz[z]);
			ans = std::min(ans, cons + b + 1ll * k * x);
		}*/
	}
	
}

template <int T>
struct fast_io {
	char p[T], *p1, *p2, q[T], *q1, *q2;
	fast_io() {
		p1 = p2 = p; q1 = q; q2 = q + T;
	}
	char gc() {
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	void pc(char ch) {
		if (q1 == q2) {
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = ch;
	}
	~fast_io() {
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1024768> io;

int read() {
	int r = 0, neg = 1;
	char ch;
	do {
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

void write(long long x) {
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	io.pc(48 + x % 10);
}

void output(long long x, char ch = ' ') {
	write(x);
	io.pc(ch);
}

int main() {
	n = read();
	for (int i = 1; i < n; ++i) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs1(1), dfs2(1);
	long long b1 = 1ll * n * (n - 1) / 2;
	long long b2 = 1ll * n * n - ans;
	assert(b2 % 2 == 0);
	output(b2 / 2 + b1, '\n');
}
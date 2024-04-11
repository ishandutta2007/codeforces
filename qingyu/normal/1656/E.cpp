#include <bits/stdc++.h>

template<int T>
struct fast_io {
	char p[T], *p1, *p2, q[T], *q1, *q2;
	fast_io() {
		p1 = p2 = p, q1 = q, q2 = q + T;
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
fast_io<1 << 20> io;
int read() {
	int r = 0, ng = 1;
	char ch;
	do {
		ch = io.gc();
		if (ch == '-') ng = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * ng;
}
void write(int x) {
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	io.pc(48 + x % 10);
}
void output(int x, char ch = ' ') {
	write(x);
	io.pc(ch);
}

int main() {
	int T = read();
	while (T--) {
		int n = read();
		std::vector<std::vector<int>> G(n + 1);
		for (int i = 1; i < n; ++i) {
			int x = read(), y = read();
			G[x].push_back(y);
			G[y].push_back(x);
		}
		std::vector<int> a(n + 1);
		auto dfs = [&](auto &self, int x, int f, int symb) -> void {
			a[x] = symb * G[x].size();
			for (int y : G[x])
				if (y != f)
					self(self, y, x, -symb);
		};
		dfs(dfs, 1, 0, 1);
		for (int i = 1; i <= n; ++i)
			output(a[i]);
		io.pc('\n');
	}
}
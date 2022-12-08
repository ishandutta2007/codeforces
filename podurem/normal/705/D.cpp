#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "dynamic"

const int MAXN = (int)5e3 + 7;
const int INF = (int)1e9 + 7;
const ll LINF = (ll)1e12 + 7;
const int MOD = (int)1e9 + 7;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x, char end = 0);
template <class Tlong = long long> inline Tlong readLong();
template <class Tlong> inline void writeLong(Tlong x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

template <class Tlong>
inline Tlong readLong() {
	int s = 1, c = readChar();
	Tlong x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

template <class Tlong>
inline void writeLong(Tlong x, char end) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

ll G[MAXN][MAXN];

struct lst {
	int v, p, n;
	lst() {}
	lst(int _v, int _p, int _n) {
		v = _v, p = _p, n = _n;
	}
};

int main() {
	file();
	int n, s, e;
	n = readInt(), s = readInt() - 1, e = readInt() - 1;
	vector<ll> x(n), a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; ++i) {
		x[i] = readInt();
	}
	for (int i = 0; i < n; ++i) {
		a[i] = readInt();
	}	
	for (int i = 0; i < n; ++i) {
		b[i] = readInt();
	}
	for (int i = 0; i < n; ++i) {
		c[i] = readInt();
	}
	for (int i = 0; i < n; ++i) {
		d[i] = readInt();
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			if (i < j) {
				G[i][j] = abs(x[i] - x[j]) + d[i] + a[j];
			} else {
				G[i][j] = abs(x[i] - x[j]) + c[i] + b[j];
			}
		}
	}
	vector<lst> A;
	A.push_back(lst(s, -1, 1));
	A.push_back(lst(e, 0, -1));
	for (int i = 0; i < n; ++i) {
		if (i == s || i == e) {
			continue;
		}
		int v = A[0].n;
		int av = 0;
		while (A[v].n != -1) {
			int nv = A[v].n;
			int anv = A[av].n;
			if (G[A[av].v][i] + G[i][A[anv].v] - G[A[av].v][A[anv].v] > G[A[v].v][i] + G[i][A[nv].v] - G[A[v].v][A[nv].v]) {
				av = v;
			}
			v = nv;
		}
		A.push_back(lst(i, av, A[av].n));
		A[A[av].n].p = A.size() - 1;
		A[av].n = A.size() - 1;
	}
	int v = 0;
	ll ans = 0;
	while (A[v].n != -1) {
		ans += G[A[v].v][A[A[v].n].v];
		v = A[v].n;
	}
	writeLong(ans);
	return 0;
}
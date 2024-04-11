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

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forq(i, q, n) for (int i = int(q); i < int(q); ++i)
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "dynamic"
#define X first
#define Y second

const int MAXN = (int)1e6 + 7;
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

int P[MAXN], F[MAXN];

int get_xor(int l, int r) {
	return P[r + 1] ^ P[l];
}

void upd(int x, int v) {
	for (int px = x; px < MAXN; px |= (px + 1)) {
		F[px] ^= v;
	}
}

int get(int x) {
	int ans = 0;
	for (int px = x; px >= 0; px = (px & (px + 1)) - 1) {
		ans ^= F[px];
	}
	return ans;
}

int main() {
	file();
	int n;
	n = readInt();
	vector<int> A(n);
	forn(i, n) {
		A[i] = readInt();
		P[i + 1] = P[i] ^ A[i];
	}
	int m, l, r;
	m = readInt();
	vector<int> ANS(m);
	vector<vector<pair<int, int> > > M(n);
	forn(i, m) {
		l = readInt();
		r = readInt();
		--l, --r;
		M[r].push_back({ l, i });
	}
	unordered_map<int, int> S;
	forn(i, n) {
		upd(i, A[i]);
		if (S.find(A[i]) != S.end()) {
			upd(S[A[i]], A[i]);
		}
		S[A[i]] = i;
		for (auto l : M[i]) {
			ANS[l.Y] = get_xor(l.X, i) ^ get(i) ^ get(l.X - 1);
		}
	}
	forn(i, m) {
		writeInt(ANS[i], '\n');
	}
	return 0;
}
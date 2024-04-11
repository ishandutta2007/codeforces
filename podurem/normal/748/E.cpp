#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <numeric>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "lasers"

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
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

const int dd = (int)1e6 + 7;
const int inf = (int)1e9 + 7;

int A[dd], Q[dd * 10];
pair<int, int> cnt[dd * 10];
int c;

inline int get(int x) {
	if (cnt[x].second == c)
		return cnt[x].first;
	cnt[x] = { 0, c };
	return 0;
}

inline void add(int x, int Y) {
	if (cnt[x].second == c)
		cnt[x].first += Y;
	else
		cnt[x] = { Y, c };
}

int solve() {
	int n, k;
	n = readInt(), k = readInt();
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		A[i] = readInt();
		sum += A[i];
	}
	sort(A, A + n);
	if (sum < k) {
		writeInt(-1);
		return 0;
	}

	int l = 1, r = min((ll)1e7, sum / k) + 1, il, ir;
	while (r - l > 1) {
		int m = (r + l) / 2;
		int cur = 0;
		for (int i = n - 1; i >= 0 && A[i] >= m; --i) {
			++c;
			add(A[i], 1);
			++cur;
			if (i && A[i] == A[i - 1]) {
				--c;
				continue;
			}
			il = 0, ir = 0;
			Q[ir++] = A[i];
			while (ir - il) {
				int Y = Q[il++];
				if (Y < (m << 1)) break;
				int K = get(Y);
				cur += K;
				if (!get((Y + 1) >> 1))
					Q[ir++] = ((Y + 1) >> 1);
				cnt[(Y + 1) >> 1].first += K;
				if (!get(Y >> 1))
					Q[ir++] = (Y >> 1);
				cnt[Y >> 1].first += K;
			}
			if (cur >= k) break;
		}

		if (cur < k)
			r = m;
		else
			l = m;
	}
	writeInt(l);
	return 0;
}
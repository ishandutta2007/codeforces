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

struct que {
	int first, second, ind;
};

int main() {
	file();
	int n, m, k;
	n = readInt(), m = readInt(), k = readInt();
	int K = 400;
	vector<int> A(n), P(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		A[i] = readInt();
		P[i + 1] = P[i] ^ A[i];
	}
	vector<vector<que> > M(n / K + 2);
	vector<pair<int, int> > Count(1 << 21, make_pair(0, -1));
	auto add = [&Count](int v, int k) {
		if (Count[v].second == k) {
			++Count[v].first;
		} else {
			Count[v] = { 1, k };
		}
	};
	auto get = [&Count](int v, int k) {
		if (Count[v].second == k) {
			return Count[v].first;
		} else {
			return 0;
		}
	};
	vector<ll> Ans(m, 0);
	for (int i = 0; i < m; ++i) {
		int l = readInt() - 1, r = readInt();
		if (l / K != r / K) {
			M[l / K].push_back({ r, l, i });
		} else {
			for (int i1 = l; i1 <= r; ++i1) {
				for (int j = i1 + 1; j <= r; ++j) {
					if ((P[i1] ^ P[j]) == k) {
						++Ans[i];
					}
				}
			}
		}
	}
	for (int i = 0; i < n / K + 2; ++i) {
		sort(all(M[i]), [](que a, que b) {
			return make_pair(a.first, a.second) < make_pair(b.first, b.second); 
		});
		int o = 0, ind = (i + 1) * K;
		ll ans = 0;
		for (int o = 0; o < (int)M[i].size(); ++o) {
			for (; M[i][o].first + 1 != ind; ++ind) {
				ans += get(P[ind] ^ k, i);
				add(P[ind], i);
			}
			for (int j = (i + 1) * K - 1; j >= M[i][o].second; --j) {
				ans += get(P[j] ^ k, i);
				add(P[j], i);
			}
			Ans[M[i][o].ind] = ans;
			for (int j = M[i][o].second; j <= (i + 1) * K - 1; ++j) {
				--Count[P[j]].first;
				ans -= get(P[j] ^ k, i);
			}
		}
	}
	for (ll i : Ans) {
		writeLong(i, '\n');
	}
	return 0;
}
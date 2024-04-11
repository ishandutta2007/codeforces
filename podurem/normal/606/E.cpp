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

const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const ll LINF = (ll)1e18 + 7;
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

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) {
		x = _x, y = _y;
	}
};

struct Vect {
	int x, y;
	Vect() {}
	Vect(int _x, int _y) {
		x = _x, y = _y;
	}
	Vect(Point a) {
		x = a.x, y = a.y;
	}
	Vect(Point a, Point b) {
		x = b.x - a.x, y = b.y - a.y;
	}
	ll operator^ (Vect d) {
		return 1ll * x * d.y - 1ll * y * d.x;
	}
};

int main() {
	file();
	int n;
	Point C;
	n = readInt(), C.x = readInt(), C.y = readInt();
	vector<Point> A(n), B;
	for (int i = 0; i < n; ++i) {
		A[i].x = readInt(), A[i].y = readInt();
	}
	sort(all(A), [](Point a, Point b) {return make_pair(a.x, a.y) > make_pair(b.x, b.y); });
	int maxy = -1;
	for (Point i : A) {
		if (i.y > maxy) {
			B.push_back(i);
			maxy = i.y;
		}
	}
	if ((Vect(B[0]) ^ Vect(B[0], C)) <= 0) {
		printf("%.10f", max(1.0 * C.x / B[0].x, 1.0 * C.y / B[0].y));
		return 0;
	}
	if ((int)B.size() == 1 || (Vect(B.back()) ^ Vect(B.back(), C)) >= 0) {
		printf("%.10f", max(1.0 * C.x / B.back().x, 1.0 * C.y / B.back().y));
		return 0;
	}
	int ind;
	for (int i = 0; i < (int)B.size() - 1; ++i) {
		if ((Vect(B[i]) ^ Vect(B[i], C)) >= 0) {
			ind = i;
		} else {
			break;
		}
	}
	double ans = 1e18;
	int uk = ind + 1;
	auto get_ans = [C](int x1, int y1, int x2, int y2) {
		double a, b;
		if (x1 * y2 - x2 * y1 == 0) {
			int yy = max(y1, y2);
			int xx = max(x1, x2);
			return 1.0 * C.x / xx + 1.0 * C.y / yy;
		} else {
			b = 1.0 * (1ll * x1 * C.y - 1ll * C.x * y1) / (1ll * x1 * y2 - 1ll * x2 * y1);
			a = 1.0 * (C.x - b * x2) / x1;
			return a + b;
		}
	};
	for (int i = ind; i >= 0; --i) {
		if (TIME > 0.023) {
			break;
		}
		int x1, y1;
		x1 = B[i].x, y1 = B[i].y;
		double cur;
		while (uk + 1 != (int)B.size() && get_ans(x1, y1, B[uk + 1].x, B[uk + 1].y) <= get_ans(x1, y1, B[uk].x, B[uk].y)) {
			++uk;
		}
		cur = get_ans(x1, y1, B[uk].x, B[uk].y);
		ans = min(ans, cur);
	}
	printf("%.10f", ans);
	return 0;
}
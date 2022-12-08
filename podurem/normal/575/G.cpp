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

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "dynamic"

const int MAXN = (int)1e5 + 7;
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

vector<int> G[MAXN][10], Q[MAXN];
pair<int, int> p[MAXN];
bool used[MAXN];
int d[MAXN], IND[MAXN], dans, vans, p2[MAXN];

int main() {
	file();
	int n, m, x, y, w;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
	    x = readInt(), y = readInt(), w = readInt();
		G[x][w].push_back(y);
		G[y][w].push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		d[i] = INF;
	}
	Q[0].push_back(0);
	d[0] = 0;
	IND[0] = 0;
	for (int i = 0; (int)Q[i].size() != 0; ++i) {
		for (int k = 0; k < 10; ++k) {
			for (auto v : Q[i]) {
				for (auto to : G[v][k]) {
					if (d[to] == INF) {
						d[to] = d[v] + 1;
						p[to] = { v, k };
						if ((int)Q[i + 1].size() == 0 || p[Q[i + 1].back()].second != k) {
							IND[to] = (int)Q[i + 1].size();
						} else {
							if (IND[v] == IND[p[Q[i + 1].back()].first]) {
								IND[to] = IND[Q[i + 1].back()];
							} else {
								IND[to] = (int)Q[i + 1].size();
							}
						}
						Q[i + 1].push_back(to);
					}
				}
			}
		}
	}
	vans = n - 1;
	deque<int> q;
	q.push_back(n - 1);
	used[n - 1] = 1;
	vector<int> d2(n, INF);
	d2[n - 1] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		if (d[v] < d[vans] || d[v] == d[vans] && IND[v] < IND[vans] || d[v] == d[vans] && IND[v] == IND[vans] && d[v] + d2[v] < d[vans] + d2[vans]) {
			vans = v;
		}
		for (auto to : G[v][0]) {
			if (!used[to]) {
				q.push_back(to);
				d2[to] = d2[v] + 1;
				used[to] = 1;
				p2[to] = v;
			}
		}
	}
	vector<int> ans;
	x = vans;
	int kol = 0;
	while (x != 0) {
		ans.push_back(x);
		writeInt(p[x].second);
		++kol;
		x = p[x].first;
	}
	if (!kol) {
	    cout << "0";
	}
	ans.push_back(0);
	reverse(all(ans));
	if (vans != n - 1) {
		x = p2[vans];
		while (x != n - 1) {
			ans.push_back(x);
			x = p2[x];
		}
		ans.push_back(x);
	}
	writeWord("\n");
	writeInt(int(ans.size()), '\n');
	for (auto i : ans) {
	    writeInt(i, ' ');
	}
	return 0;
}
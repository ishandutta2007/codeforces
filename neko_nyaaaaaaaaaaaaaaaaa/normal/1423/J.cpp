//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

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

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
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

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

const int M = 1e9+7;
const int MOD = M;

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	inline modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	inline modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

template<const int n, const int m, class T = modBase<>>
struct Matrix {
	T v[n][m];
	
	Matrix(int d = 0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				v[i][j] = T(0);
			}
			if(i < m) {
				v[i][i] = T(d);
			}
		}
	}
	
	template<int mm>
	Matrix<n, mm, T> operator *(const Matrix<m, mm, T> &o) {
		Matrix<n, mm, T> ans;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < mm; j++) {
				for(int k = 0; k < m; k++) {
					ans.v[i][j] = ans.v[i][j] + v[i][k] * o.v[k][j];
				}
			}
		}
		return ans;
	}
};

long long m;

const int MAGIC = 15;
std::vector<Matrix<8, 8>> wtf[MAGIC+1];

void solve() {
	m = readInt<long long>();
	//cin >> m;
	//m = 1e18;
	int n = 0;
	while((1LL << n) <= m) n++;
	Matrix<8, 1> ans;
	for(int i = 0; i < 8; i++) {
		ans.v[i][0] = 1;
	}
	int mask = 0;
	int got = 0;
	for(int i = n-1; i >= 0; i--) {
		int b = (m >> i) & 1;
		mask |= b << (got++);
		if(i == 0 || got == MAGIC) {
			ans = wtf[got][mask] * ans;
			got = mask = 0;
		}
	}
	writeInt(ans.v[0][0].val, '\n');
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Matrix<8, 8> pre[2];
	for(int b = 0; b < 2; b++) {
		for(int j = 0; j < 8; j++) {
			int o = b != (j & 1);
			o = (j + o) >> 1;
			pre[b].v[j][o+3] = 1;
			if(j > 0) {
				for(int k = 0; k < 8; k++) {
					pre[b].v[j][k] += pre[b].v[j-1][k];
				}
			}
			if(o > 0) {
				pre[b].v[j][o-1] -= 1;
			}
		}
	}
	wtf[0].push_back(Matrix<8, 8>(1));
	for(int i = 0; i < MAGIC; i++) {
		for(int j = 0; j < (1 << i); j++) {
			wtf[i+1].push_back(pre[0] * wtf[i][j]);
		}
		for(int j = 0; j < (1 << i); j++) {
			wtf[i+1].push_back(pre[1] * wtf[i][j]);
		}
	}
	int t = 500000; //cin >> t;
	t = readInt<int>();
	while (t--) {
		solve();
	}

	return 0;
}
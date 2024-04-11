#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

#define FNAME ""

template <class T = int> inline T readInt();            
inline double readDouble();
inline int readUInt();           
inline int readChar();           
inline void readWord(char *s); 
inline bool readLine(char *s); // do not save '\n'
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt(T x, int len);
template <class T> inline void writeUInt(T x, int len);
template <class T> inline void writeInt(T x) { writeInt(x, -1); };
template <class T> inline void writeUInt(T x) { writeUInt(x, -1); };
inline void writeChar(int x); 
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();


const int MAX_N = 1e6 + 5;

vector<char> a[MAX_N], b[MAX_N], c[MAX_N]; 
vi sum[MAX_N], sum2[MAX_N];
char r[MAX_N];

bool check(int n, int m, int bm) {
 	int k = (2 * bm + 1) * (2 * bm + 1);
 	forn (i, n + 1)
 		forn (j, m + 1)
			b[i][j] = c[i][j] = 0;	
 	forab (i, bm, n - bm)
 		forab (j, bm, m - bm)
 			if (sum[i + bm + 1][j + bm + 1] + sum[i - bm][j - bm] - sum[i - bm][j + bm + 1] - sum[i + bm + 1][j - bm] == k) {
 			 	b[i + bm + 1][j + bm + 1]++, b[i - bm][j - bm]++;
 			 	b[i - bm][j + bm + 1]--, b[i + bm + 1][j - bm]--;
 			 	c[i][j] = 1;
 			}
 	forn (i, n) 
 		forn (j, m) {
 			sum2[i + 1][j + 1] = sum2[i + 1][j] + sum2[i][j + 1] - sum2[i][j] + b[i][j];
			if (a[i][j] != (sum2[i + 1][j + 1] >= 1))
				return 0;
		}
	return 1;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

	int n = readInt(), m = readInt();
	//cin >> n >> m;
	forn (i, n + 1)
		a[i].resize(m + 1), b[i].resize(m + 1), c[i].resize(m + 1), sum[i].resize(m + 1), sum2[i].resize(m + 1);
	//string s;
	forn (i, n) {
		readLine(r);
		//cin >> s;
		forn (j, m)
			a[i][j] = (r[j] == 'X');
	}
	forn (i, n)
		forn (j, m)
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
	int bl = 0, br = min(n, m) + 1;
	while (br - bl > 1) {
		int bm = (bl + br) / 2;
	 	bool ok = check(n, m, bm);	
		if (ok)
			bl = bm;
		else
			br = bm;
	}
	check(n, m, 1);
	check(n, m, bl);
	//cout << bl << "\n";
	writeInt(bl);
	writeChar('\n');
	forn (i, n) {
		forn (j, m)
			if (c[i][j])
				r[j] = 'X';
			else
				r[j] = '.';
		r[m] = '\n';
		writeWord(r);
		//cout << s << "\n";
	}
	flush();
	return 0;
}



const int BUF_SIZE = 4096;

char buf[BUF_SIZE];
int bufLen = 0, pos = 0;

inline bool isEof() {
	if (pos == bufLen) {
		pos = 0, bufLen = fread(buf, 1, BUF_SIZE, stdin);
		if (pos == bufLen)
			return 1;
	}
	return 0;
}

inline int getChar() { 
	return isEof() ? -1 : buf[pos++];
}

inline int peekChar() { 
	return isEof() ? -1 : buf[pos];
}

inline bool seekEof() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		pos++;
	return c == -1;
}

inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}

inline int readUInt() {
	int c = readChar(), x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
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

inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
	x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}

inline void readWord(char *s) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine(char *s) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}


int writePos = 0;
char writeBuf[BUF_SIZE];

inline void writeChar(int x) {
	if (writePos == BUF_SIZE)
		fwrite(writeBuf, 1, BUF_SIZE, stdout), writePos = 0;
	writeBuf[writePos++] = x;
}

inline void flush() {
	if (writePos)
		fwrite(writeBuf, 1, writePos, stdout), writePos = 0;
}

template <class T> 
inline void writeInt(T x, int outputLen) {
	if (x < 0)
		writeChar('-'), x = -x;
	
	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < outputLen)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
}

template <class T> 
inline void writeUInt(T x, int outputLen) {
	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + char(x % 10), x /= 10;
	while (n < outputLen)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
}

inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble(double x, int outputLen) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int) x;
	writeUInt(t), x -= t;
	writeChar('.');
	for (int i = outputLen - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int) x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}
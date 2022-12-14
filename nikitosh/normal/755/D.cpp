#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 2e6 + 5;

int t[MAX_N], n;


inline int readChar();
inline int readInt();
template <class T> inline void writeInt( T x );

inline int readChar() {
  int c = getchar();
  while (c <= 32)
    c = getchar();
  return c;
}

inline int readInt() {
  int s = 0, c = getchar(), x = 0;
  if (c == '-')
    s = 1, c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return s ? -x : x;
}

template <class T> inline void writeInt( T x ) {
  if (x < 0)
    putchar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    putchar(s[n]);
}




int get(int ind) {
 	int res = 0;
 	for (; ind >= 0; ind &= (ind + 1), ind--)
 		res += t[ind];
 	return res;
}

void add(int ind, int x) {
 	for (; ind < n; ind |= (ind + 1))	
 		t[ind] += x;
}

int sum(int l, int r) { //[l, r)
	return get(r - 1) - get(l - 1);
}

int getSum(int &cur, int n, int k) {
 	int l = cur;
 	cur += k;
 	if (cur < n)
 		return sum(l + 1, cur);
 	cur -= n;
 	return sum(l + 1, n) + sum(0, cur);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int k;
	scanf("%d%d", &n, &k);
	k = min(k, n - k);
	int cur = 0;
	ll ans = 1;
	forn (i, n) {
		ans += 2 * getSum(cur, n, k) + 1;
		if (cur < k && cur > 0)
			ans++;
		writeInt(ans);
		putchar(' ');
		add(cur, 1);
	}
	return 0;
}
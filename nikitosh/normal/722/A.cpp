#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
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

int check(int type, int h, int m) {
	if (m >= 60)
		return 0;
	if (type == 0 && !(h >= 1 && h <= 12))
		return 0;
	if (type == 1 && !(h >= 0 && h <= 23))
		return 0;
	return 1;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int type;
	char h1, h2, m1, m2;
	scanf("%d %c%c:%c%c", &type, &h1, &h2, &m1, &m2);
	h1 -= '0', h2 -= '0', m1 -= '0', m2 -= '0';
	if (type == 12)
		type = 0;
	else
		type = 1;
	int maxx = -1, x = 0, y = 0, z = 0, t = 0;
	forn (i, 10000) {
		int h = i / 100, m = i % 100;
		if (check(type, h, m)) {
			int cnt = (h / 10 == h1) + (h % 10 == h2) + (m / 10 == m1) + (m % 10 == m2); 
			if (cnt > maxx) 
				maxx = cnt, x = h / 10, y = h % 10, z = m / 10, t = m % 10;
	   	}
   	}
   	printf("%d%d:%d%d\n", x, y, z, t);
	return 0;
}
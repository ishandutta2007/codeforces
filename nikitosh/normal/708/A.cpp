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

const int MAX_N = 1e6 + 5;

char s[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	gets(s);
	int len = strlen(s);
	bool allA = 1;	
	forn (i, len)
		if (s[i] != 'a')
			allA = 0;
	if (allA) {
		forn (i, len - 1)
			printf("a");
		printf("z");
		puts("");
		return 0;
	}
	int j = len;
	forn (i, len) {
		if (s[i] != 'a') {
			j = i;
			break;
		} 
		printf("%c", s[i]);
	}	
	int oldJ = j;
	forab (i, j, len) { 
		if (s[i] == 'a') {
		 	j = i;
		 	break;
		}
		printf("%c", s[i] - 1);
	}
	if (j != oldJ)
		forab (i, j, len)
			printf("%c", s[i]);
	return 0;
}
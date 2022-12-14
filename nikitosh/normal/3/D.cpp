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

const int MAX_N = 1e5;

char s[MAX_N];
int a[MAX_N], b[MAX_N];
set<pii> options;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	gets(s);
	int n = strlen(s);
	int m = 0;
	forn (i, n)
		if (s[i] == '?')
			m++;	
	forn (i, m)
		scanf("%d%d", &a[i], &b[i]);
	int cur = 0, bal = 0;
	ll ans = 0;
	forn (i, n) {
		if (s[i] == '(')
			bal++;
		if (s[i] == ')')
			bal--;
		if (s[i] == '?') {
			ans += b[cur];
			bal--;
			s[i] = ')';
			options.insert(mp(a[cur] - b[cur], i));
			cur++;
		}
		if (bal < 0) {
			if (!sz(options)) {
			 	puts("-1");
			 	return 0;
			}
			auto it = options.begin();
		 	ans += it->fs;
		 	s[it->sc] = '(';
		 	bal += 2;
		 	options.erase(it);
		}
   	}
   	if (bal != 0) {
   		puts("-1");
   		return 0;
   	}
   	printf(I64 "\n", ans);
   	puts(s);
	return 0;
}
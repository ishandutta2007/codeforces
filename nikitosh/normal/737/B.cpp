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

const int MAX_N = 2e5 + 5;

char s[MAX_N];
vector<pii> v;
vi ans;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, a, b, k;
	scanf("%d%d%d%d\n", &n, &a, &b, &k);
	gets(s);
	forn (i, n)
		if (s[i] == '0') {
		 	int it = i;
		 	while (it < n && s[it] == '0')
		 		it++;
		   	v.pb(mp(i, it - i));
		   	i = it - 1;
		}
	int allCnt = 0;
	forn (i, sz(v)) {		
		allCnt += v[i].sc / b;	
		int cur = v[i].fs + b - 1;
		while (v[i].sc >= b)
			ans.pb(cur), v[i].sc -= b, cur += b;
	}
	ans.resize(allCnt - a + 1);
	printf("%d\n", sz(ans));
	for (int k : ans)
		printf("%d ", k + 1);
	return 0;
}
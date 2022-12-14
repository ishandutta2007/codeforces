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
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MOD = 1e9 + 7;
const int MAX_N = 1e3 + 5;

int p[MAX_N][MAX_N];

int add(int a, int b) {
 	a += b;
 	return a >= MOD ? a - MOD : a;
}

int mul(int a, int b) {
 	return (a * 1ll * b) % MOD;
}

int power(int a, int n) {
 	if (n == 0)
 		return 1;
 	if (n % 2 == 1)
 		return mul(a, power(a, n - 1));
 	int s = power(a, n / 2);
 	return mul(s, s);
}

int inv(int a) {
 	return power(a, MOD - 2);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int k, pA, pB;
	scanf("%d%d%d", &k, &pA, &pB);
	int invv = inv(pA + pB);
	int a = mul(pA, invv), b = mul(pB, invv); 	
	p[1][0] = 1;
	int ans = 0;
	forab (cnt, 1, k + 1)
		forn (j, k) {
		 	if (cnt == 1 && j == 0)
		 		continue;
		 	int sec = 0;
		   	if (j >= cnt)
		   		sec = mul(p[cnt][j - cnt], b);
		 	p[cnt][j] = add(mul(p[cnt - 1][j], a), sec);
		 	if (cnt < k && cnt + j >= k)
		 		ans = add(ans, mul(mul(p[cnt][j], b), cnt + j));
		}
	forn (j, k) {
	 	int c = mul(add(pA, pB), inv(pB));
	 	ans = add(ans, mul(b, mul(k + j, mul(p[k][j], c))));
	 	ans = add(ans, mul(b, mul(a, mul(p[k][j], mul(c, c)))));
	}
	printf("%d\n", ans);
	return 0;
}
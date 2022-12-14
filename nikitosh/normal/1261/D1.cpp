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

const int MAX_N = 2e5 + 5, MOD = 998244353;

int a[MAX_N], two[MAX_N], fact[MAX_N], revFact[MAX_N];

int mul(int x, int y) {
 	return (x * 1ll * y) % MOD;
}

int add(int x, int y) {
 	x += y;
 	return x >= MOD ? x - MOD : x;
}

int sub(int x, int y) {
 	x -= y;
 	return x < 0 ? x + MOD : x;
}

int c(int n, int k) {
 	return mul(mul(fact[n], revFact[k]), revFact[n - k]);
}

int power(int x, int n) {
	if (!n)
		return 1;
	int b = power(x, n / 2);
	b = mul(b, b);
	return n & 1 ? mul(x, b) : b;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];
	if (k == 1) {
		cout << 0;
		return 0;
	}
	a[n] = a[0];
	int b = 0;
	forn (i, n)
		if (a[i] == a[i + 1])
			b++;
	int ans = 1;
	forn (i, b)
		ans = mul(ans, k);
	n -= b;

	fact[0] = two[0] = 1;
	forab (i, 1, n + 1) {
		fact[i] = mul(fact[i - 1], i);
		two[i] = add(two[i - 1], two[i - 1]);
	}
	revFact[n] = power(fact[n], MOD - 2);
	for (int i = n - 1; i >= 0; i--)
		revFact[i] = mul(revFact[i + 1], i + 1);
	int ans2 = 0;
	int curDegK = 1;
	forn (i, n + 1) {
		int x = two[n - i];
		if ((n - i) % 2 == 0)
			x = sub(x, c(n - i, (n - i) / 2));
		if (x % 2 == 0)
			x /= 2;
		else
			x = (x + MOD) / 2;
		ans2 = add(ans2, mul(curDegK, mul(c(n, i), x)));				 	
		curDegK = mul(curDegK, k - 2);
	}
	cout << mul(ans, ans2); 
	return 0;
}
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
  
const int N = 2e5 + 5, MOD = 998244353;

int dp[N], dp2[N], p[N];  
  
set<pii> s;  
int res = 0;
  
int mul(int a, int b) {
	return (a * 1ll * b) % MOD;
}  

int power(int a, int n) {
	if (n == 0)
		return 1;
	int b = power(a, n / 2);
	b = mul(b, b);
	return n & 1 ? mul(b, a) : b;
}

int rev(int a) {
	return power(a, MOD - 2);
}

int divv(int a, int b) {
	return mul(a, rev(b));
}
  
int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}  
  
int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + MOD : a;
}
  
void insert(int ind, int val) {
	res = add(res, val);
	s.insert(mp(ind, val));
}  

void erase(int ind, int val) {
	res = sub(res, val);
	s.erase(mp(ind, val));
}  

int get(int l, int r) {
	int y = divv(dp[l], dp[r]); 
	int x = sub(dp2[l], mul(dp2[r], y));
	return divv(x, y);
}
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, q;
	cin >> n >> q;
	forn (i, n) {
		cin >> p[i];
		p[i] = divv(p[i], 100);
	}
	dp[n] = 1;
	fornr (i, n)
		dp[i] = mul(dp[i + 1], p[i]);
	dp2[n] = 1;
	fornr (i, n)
		dp2[i] = add(1, mul(dp2[i + 1], p[i]));
	insert(0, divv(dp2[0], dp[0]));
	insert(n, 0);
	forn (qq, q) {
		int ind;
		cin >> ind;
		ind--;
		auto it = s.lower_bound(mp(ind, -1));
		if (it->fst != ind) {
			int nxt = it->fst;
			it--;
			int prev = it->fst;
			erase(it->fst, it->snd);
			insert(prev, get(prev, ind));
			insert(ind, get(ind, nxt));
		} else {
			int val = it->snd;
			it++;
			int nxt = it->fst;
			it--;
			it--;
			int prev = it->fst;
			erase(it->fst, it->snd);
			erase(ind, val);
			insert(prev, get(prev, nxt));
		}
		cout << res << "\n";
	}
	
	return 0;
}
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
  
const int N = 4e5 + 5, MOD = 998244353;

int p[N];
  
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
		cin >> p[i];
	cout << n * 1ll * k - (k - 1) * 1ll * k / 2;
	int ind = -1;
	int ans = 1;
	forn (i, n)
		if (p[i] > n - k) {
			if (ind != -1)
				ans = (ans * 1ll * (i - ind)) % MOD;
			ind = i;
		}
	cout << " " << ans << "\n";	
	return 0;
}
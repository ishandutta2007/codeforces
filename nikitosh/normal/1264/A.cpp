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
  
const int N = 4e5 + 5;

int a[N];
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int tn;
	cin >> tn;
	forn (tt, tn) {
		int n;
		cin >> n;
		forn (i, n)
			cin >> a[i];
		int cur = 0;
		vi v;
		forn (i, n) {
			cur++;
			if (i == n - 1 || a[i] != a[i + 1])
				v.pb(cur), cur = 0;
		}
		int x = 0, y = 0, z = 0;
		int k = v[0];
		int curSum = 0, ind = -1;
		forab (i, 1, sz(v)) {
			curSum += v[i];
			if (curSum > k) {
				ind = i + 1;
				break;
			}
		}
		if (curSum <= k) {
			cout << x << " " << y << " " << z << "\n";
			continue;			
		}
		int curSum2 = 0;
		forab (i, ind, sz(v)) {
			curSum2 += v[i];
			if (curSum2 > k && k + curSum + curSum2 <= n / 2) {
				x = k, y = curSum, z = curSum2;
			}
		}
		cout << x << " " << y << " " << z << "\n";		
	}
	
	return 0;
}
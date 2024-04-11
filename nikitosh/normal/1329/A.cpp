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
  
const int N = 2e5 + 5;

int a[N], st[N];  
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	forn (i, m) {
		cin >> a[i];
		if (a[i] > n - i) {
			cout << "-1\n";
			return 0;
		}
		sum += a[i];
	}
	if (sum < n) {
		cout << "-1\n";
		return 0;
	}
	forn (i, m)
		st[i] = i;
	int last = n;
	fornr (i, m) {
		if (i + a[i] < last) {
			st[i] = last - a[i];
			last -= a[i];
		} else
			break;
	}
	forn (i, m)
		cout << st[i] + 1 << " ";
	cout << "\n";
	return 0;
}